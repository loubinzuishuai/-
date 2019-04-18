#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace std;
using namespace cv;
const int slider_max = 64;
int slider;
Mat image;
Mat result;

void colorReduce(Mat &inputImage, Mat &outputImage, int div)
{
	outputImage = inputImage.clone();
	int rows = inputImage.rows;
	int cols = inputImage.cols * inputImage.channels();
	if (inputImage.isContinuous())
	{
		cols *= rows;
		rows = 1;
	}
	for (int i = 0; i < rows; i++)
	{
		uchar *dataout = outputImage.ptr<uchar>(i);
		for (int j = 0; j < cols; j++)
		{
			dataout[j] = dataout[j] / div * div + div / 2;//指针也可以像数组一样用索引访问
		}
	}
}
void ontrackBar(int pos, void *)
{
	if (pos <= 0)
		result = image;
	else
		colorReduce(image, result, pos);
	imshow("显示结果", result);
}
int main()
{
	image = imread("f:\\图片\\小包总.jpg");
	namedWindow("原图片");
	namedWindow("显示结果");
	slider = 0;
	createTrackbar("ColorReduce", "显示结果", &slider, slider_max, ontrackBar);
	imshow("原图片", image);
	imshow("显示结果", image);
	waitKey(0);
	return 0;
}
