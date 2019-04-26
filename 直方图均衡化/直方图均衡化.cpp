#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
using namespace std;
using namespace cv;

int main()
{
	Mat src;
	src = imread("f:\\图片\\小包总.jpg");
	if (src.data)
	{
		int b[256] = { 0 }, g[256] = { 0 }, r[256] = { 0 }; //定义数组统计bgr通道的灰度值
		//统计频数
		Mat_<Vec3b>::iterator it_b = src.begin<Vec3b>();
		Mat_<Vec3b>::iterator it_e = src.end<Vec3b>();
		for (Mat_<Vec3b>::iterator it = it_b; it != it_e; it++)
		{
			b[(*it)[0]]++;
			g[(*it)[1]]++;
			r[(*it)[2]]++;
		}

		//均衡化
		int m_size = src.rows*src.cols;
		double sum[3] = { 0 };
		for (int i = 0; i < 256; i++)
		{
			sum[0] += b[i];
			b[i] = (sum[0] / m_size) * 255;
			sum[1] += g[i];
			g[i] = (sum[1] / m_size) * 255;
			sum[2] += r[i];
			r[i] = (sum[2] / m_size) * 255;
		}

		//创建均衡化后的图像
		Mat dst = src.clone();
		Mat_<Vec3b>::iterator it_b1 = dst.begin<Vec3b>();
		Mat_<Vec3b>::iterator it_e1 = dst.end<Vec3b>();
		for (Mat_<Vec3b>::iterator it1 = it_b1, it = it_b; it1 != it_e1&&it != it_e; it++, it1++)
		{
			(*it1)[0] = b[(*it)[0]];
			(*it1)[1] = b[(*it)[1]];
			(*it1)[2] = b[(*it)[2]];
		}
		namedWindow("原图像");
		namedWindow("均衡化后");
		imshow("原图像", src);
		imshow("均衡化后", dst);
	}
	waitKey(0);
	return 0;
}