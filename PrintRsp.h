/*
 * PrintRsp.h
 *
 *  Created on: Feb 6, 2014
 *      Author: kucho
 */
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include <math.h>

using namespace cv;
using namespace std;

void print_rsp(int count);

void print_rsp(int count) {
	if(count>=6){
		cout << "paper" << endl;
	}
	else if(count == 4 || count == 5) {
		cout << "scissors" << endl;
	}
	else {
		cout << "rock" << endl;
	}
}
