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
			dataout[j] = dataout[j] / div * div + div / 2;//ָ��Ҳ����������һ������������
		}
	}
}
void ontrackBar(int pos, void *)
{
	if (pos <= 0)
		result = image;
	else
		colorReduce(image, result, pos);
	imshow("��ʾ���", result);
}
int main()
{
	image = imread("f:\\ͼƬ\\С����.jpg");
	namedWindow("ԭͼƬ");
	namedWindow("��ʾ���");
	slider = 0;
	createTrackbar("ColorReduce", "��ʾ���", &slider, slider_max, ontrackBar);
	imshow("ԭͼƬ", image);
	imshow("��ʾ���", image);
	waitKey(0);
	return 0;
}
