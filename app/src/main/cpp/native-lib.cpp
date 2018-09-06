#include <jni.h>
#include <string>
#include <opencv2/opencv.hpp>
#include "BitmapMatUtils.h"
#include "cardocr.h"


using namespace cv;


extern "C"
JNIEXPORT jstring JNICALL
Java_zeller_com_opencvexample_BankCardOcr_cardOcr(JNIEnv *env, jclass type, jobject bitmap) {

    // TODO
    Mat mat;
    bitmap_to_mat(env, bitmap, mat);

    Rect card_rect;
    co1::find_card_area(mat, card_rect);

    Mat card_mat(mat, card_rect);
    imwrite("/storage/emulated/0/ocr/card_mat.jpg", card_mat);

    return env->NewStringUTF("123456");
}