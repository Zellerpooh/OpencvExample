//
// Created by Administrator on 2018/9/6.
//

#include "cardocr.h"
#include <android/log.h>
#include <vector>

using namespace std;

static const char *const LOG_TAG = "native-lib";
#define LOG_D(...) __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, __VA_ARGS__)


int co1::find_card_area(const Mat &mat, Rect &srcRect) {
    Mat blur;
    GaussianBlur(mat, blur, Size(5, 5), BORDER_DEFAULT, BORDER_DEFAULT);

    // 梯度增强 , x 轴和 y 轴
    Mat grad_x, grad_y;
    Scharr(blur, grad_x, CV_32F, 1, 0);
    Scharr(blur, grad_y, CV_32F, 0, 1);
    Mat grad_abs_x, grad_abs_y;
    convertScaleAbs(grad_x, grad_abs_x);
    convertScaleAbs(grad_y, grad_abs_y);
    Mat grad;
    addWeighted(grad_abs_x, 0.5, grad_abs_y, 0.5, 0, grad);

    imwrite("/storage/emulated/0/ocr/bank_card.jpg", grad);
    __android_log_print(ANDROID_LOG_ERROR, "TAG_face", "%d, %d, %d", grad.cols, grad.rows,
                        grad.type());

    // 二值化，进行轮廓查找
    Mat gray;
    cvtColor(grad, gray, COLOR_BGRA2GRAY);
    Mat binary;
    threshold(gray, binary, 40, 255, THRESH_BINARY);

    imwrite("/storage/emulated/0/ocr/binary_n.jpg", binary);

    vector<vector<Point> > contours;
    findContours(binary, contours, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);
    for (int i = 0; i < contours.size(); ++i) {
        Rect rect = boundingRect(contours[i]);
        // 是不是符合规则
        if (rect.width > mat.cols / 2 && rect.width != mat.cols && rect.height > mat.rows / 4) {
            LOG_D("找到轮廓");
            srcRect = rect;
            break;
        }
    }

    // release source
    blur.release();
    grad_x.release();
    grad_y.release();
    grad_abs_x.release();
    grad_abs_y.release();
    grad.release();
    gray.release();
    binary.release();

    return 1;
}