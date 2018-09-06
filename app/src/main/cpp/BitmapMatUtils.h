//
// Created by Administrator on 2018/9/6.
//

#ifndef OPENCVEXAMPLE_BITMAPMATUTILS_H
#define OPENCVEXAMPLE_BITMAPMATUTILS_H

#include <opencv2/opencv.hpp>
#include <android/bitmap.h>

using namespace cv;

void bitmap_to_mat(JNIEnv *env, jobject &srcBitmap, Mat &srcMat);

void mat_to_bitmap(JNIEnv *env, Mat &srcMat, jobject &dstBitmap);


#endif //OPENCVEXAMPLE_BITMAPMATUTILS_H
