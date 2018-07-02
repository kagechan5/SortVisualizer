#include "stdafx.h"
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
using namespace std;
using namespace cv;



int main() {
	int tmp, babble[100];
	bool frag[100] = { false };
	for (int i = 0; i < 100; i++) {
		tmp = rand() % 100;
		if (frag[tmp]) {
			i--;
			continue;
		}
		babble[i] = tmp;
		frag[tmp] = true;

	}

	for (int i = 0; i < 100; i++) {
		cout << babble[i] << endl;

	}

	//cvNamedWindow("window");

	cv::Mat img(cv::Size(640, 480), CV_8UC3, cv::Scalar(0, 0, 255));
	/*img.data[240*img.step + 320 * img.channels() + 0] = 255;
	img.cols;
	img.rows;
	img.step = img.cols * img.channels();
	*/

	



	cv::rectangle(img, cv::Point(300, 450), cv::Point(400, 480), cv::Scalar(200, 0, 0), -1);
	cv::imshow("red image", img);
	cv::waitKey(0);


}

