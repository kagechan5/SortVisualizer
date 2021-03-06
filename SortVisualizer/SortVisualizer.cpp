﻿#include "stdafx.h"
#include<iostream>
#include<random>

#ifdef _DEBUG
#define CV_EXT "d.lib"
#else
#define CV_EXT ".lib"
#endif
#pragma comment(lib, "opencv_world400" CV_EXT) // OpenCV3.3.0の場合は、"opencv_core330"に
//#pragma comment(lib, "opencv_highgui340" CV_EXT) // OpenCV3.3.0の場合は、"opencv_highgui330"に変更

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>
#define N 100
using namespace std;
using namespace cv;

static cv::Mat img(cv::Size(680, 480), CV_8UC3, cv::Scalar(0,0,0));

void drawline(Mat img,int a[N]) {
	for (int i = 0; i < N; i++) {
		cv::line(img, cv::Point(680/100*i, 480), cv::Point(680/100*i, 480-4*a[i]), cv::Scalar(200, 0, 0), 2, 4);
		cv::line(img, cv::Point(680/100 * i, 480 - 4 * a[i]), cv::Point(680/100 * i, 0), cv::Scalar(0, 0,0), 2, 4);
		cv::imshow("red image", img);
		cv::waitKey(1);
	}
}

void drawline2(Mat img, int a[N],int j,int k) {
		
		cv::line(img, cv::Point(680/100 * j, 480), cv::Point(680/100 * j, 480 - 4 * a[j]), cv::Scalar(200, 0, 0), 2, 4);
		cv::line(img, cv::Point(680/100 * j, 480 - 4 * a[j]), cv::Point(680/100 * j, 0), cv::Scalar(0,0,0), 2, 4);
		cv::line(img, cv::Point(680/100 * k, 480), cv::Point(680/100 * k, 480 - 4 * a[k]), cv::Scalar(200, 0, 0), 2, 4);
		cv::line(img, cv::Point(680/100 * k, 480 - 4 * a[k]), cv::Point(680/100 * k, 0), cv::Scalar(0,0,0), 2, 4);

		cv::imshow("red image", img);
		cv::waitKey(1);
	
}

void babblesort(int a[N]) {
	int i, j, t;
	drawline(img, a);
	for (i = 0; i < N - 1; i++) {
		for (j = N - 1; j > i; j--) {
			if (a[j - 1 ]> a[j]) {
				t = a[j]; a[j] = a[j - 1]; a[j - 1] = t;
				drawline2(img, a,j-1,j);
			}
			
		}
	}
}

int main() {
	int tmp, babble[N];
	bool frag[N] = { false };
	for (int i = 0; i < N; i++) {
		tmp = rand() % N;
		if (frag[tmp]) {
			i--;
			continue;
		}
		babble[i] = tmp;
		frag[tmp] = true;

	}

	

	babblesort(babble);
	
	
	waitKey(0);
	


	
	


}

