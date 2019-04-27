#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
using namespace std;
using namespace cv;
//at函数返回图像m的位于(i,j)的像素的，flag=0,1,2分别表示返回b,g,r通道,
//当访问边界之外像素时，采用复制边界像素的方法。
unsigned int at(Mat &m, int i, int j, int flag)
{
	if (i >= 0 && i < m.rows)
	{
		if (j >= 0 && j < m.cols)
			return m.at<Vec3b>(i, j)[flag];
		else if (j < 0)
			return m.at<Vec3b>(i, 0)[flag];
		else
			return m.at<Vec3b>(i, m.cols - 1)[flag];
	}
	else if (i < 0)
	{
		if (j >= 0 && j < m.cols)
			return m.at<Vec3b>(0, j)[flag];
		else if (j < 0)
			return m.at<Vec3b>(0, 0)[flag];
		else
			return m.at<Vec3b>(0, m.cols - 1)[flag];
	}
	else
	{
		if (j >= 0 && j < m.cols)
			return m.at<Vec3b>(m.rows-1, j)[flag];
		else if (j < 0)
			return m.at<Vec3b>(m.rows-1, 0)[flag];
		else
			return m.at<Vec3b>(m.rows-1, m.cols - 1)[flag];
	}
}
//将图像在像素点(i, j)的3*3邻域与模板相乘，结果存在数组product中，templet是模板
void multiply(Mat &m, int i, int j, float templet[3][3], float product[3])
{
	for (int k = 0; k < 3; k++) //k表示像素通道
	{
		float result = 0;
		for (int x = 0; x < 3; x++)
		{
 			for (int y = 0; y < 3; y++)
			{
					float value = at(m, i - 1 + x, j - 1 + y, k);
					result += templet[x][y] * value;
			}
		}
		product[k] = result;
	}
}
void mean_filter(Mat &src, Mat &dst)
{
	dst = src.clone();
	float templet[3][3];
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			templet[i][j] = 1.0 / 9;
	for (int i = 0; i < src.rows; i++)
	{
		for (int j = 0; j < src.cols; j++)
		{
			float product[3]; //product[0]是b通道与模板的乘积，/product[1]是g通道与模板的乘积，/product[2]是r通道与模板的乘积，
			multiply(src, i, j, templet, product);
			for (int k = 0; k < 3; k++)
				dst.at<Vec3b>(i, j)[k] = product[k];
		}
	}
}
int main()
{

	Mat image = imread("f:\\图片\\lenna.jpg");		//变换前图像
	Mat result = image.clone();
	mean_filter(image, result);
	namedWindow("原图像", 0);
	resizeWindow("原图像", 500, 500);
	namedWindow("均值滤波", 0);
	resizeWindow("均值滤波", 500, 500);
	imshow("原图像", image);
	imshow("均值滤波", result);
	waitKey(0);
	return 0;
}