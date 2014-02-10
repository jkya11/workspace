/*
 * countFingers.cpp
 *
 *  Created on: Feb 6, 2014
 *      Author: kucho
 */

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include <math.h>
#include <PrintRsp.h>

using namespace cv;
using namespace std;

void count_fingers(Mat image);

void count_fingers(Mat image)
{
	/*
	if(! image.data)
	{
		cout << "Could not open or find the image" << std::endl;
		return -1;
	}
	*/
	//namedWindow( "Display window", WINDOW_AUTOSIZE);
	//imshow("Display window", image);

	//waitKey(0);
	//counting the fingers
	int flag=0;
	int i=1;
	int count=0; //count : number of fingers*2
	double k=0.33; //k : ratio of y value to get a line
	int alpha=floor((image.rows)*k); //alpha : the position of y value of line
	int threshold_pixel = 20; //threshold_pixel : threshold value to ignore noise
	int data; //data :

	//rows : size of y axis, cols : size of x axis
	//cout << image.rows << endl;
	//cout << image.cols << endl;

	for(i=1; i<=image.cols; i++) {
		//cout << i << " " << (int) image.at<Vec3b>(50, i)[1] << endl;
		data = (int) image.at<Vec3b>(alpha,i)[1];
		if(data >= threshold_pixel) {
			flag=1;
		}
		else {
			if(flag==1) {
				flag=0;
				count++;
			}
		}
	}

	cout << "number of contours that a line meets : " << count << endl;
	print_rsp(count);
	//return 0;
}
