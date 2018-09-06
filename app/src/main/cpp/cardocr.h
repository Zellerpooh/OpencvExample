//
// Created by Administrator on 2018/9/6.
//

#ifndef OPENCVEXAMPLE_CARDOCR_H
#define OPENCVEXAMPLE_CARDOCR_H

#include <opencv2/opencv.hpp>

using namespace cv;

namespace co1 {

    int find_card_area(const Mat &mat, Rect &srcRect);

}

#endif //OPENCVEXAMPLE_CARDOCR_H
