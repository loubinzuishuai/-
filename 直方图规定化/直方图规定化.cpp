//#include <iostream>
//#include <cmath>
//#include <opencv2/core/core.hpp>
//#include <opencv2/highgui/highgui.hpp>
//using namespace std;
//using namespace cv;
//void statistics(Mat &m, float b[256], float g[256], float r[256])
//{
//	for (int i = 0; i < 256; i++)
//		b[i] = g[i] = r[i] = 0;
//	Mat_<Vec3b>::iterator it_begin = m.begin<Vec3b>();
//	Mat_<Vec3b>::iterator it_end = m.end<Vec3b>();
//	for (Mat_<Vec3b>::iterator it = it_begin; it != it_end; it++)
//	{
//		b[(*it)[0]] += 1;
//		g[(*it)[1]] += 1;
//		r[(*it)[2]] += 1;
//	}
//	float sum = m.rows * m.cols;
//	for (int i = 0; i < 256; i++)
//	{
//		b[i] /= sum;
//		g[i] /= sum;
//		r[i] /= sum;
//	}
//}
//
////�����Ѹ���bgr��ֱ��ͼ�ֲ�����ͼ��work���й涨����
//void specification(Mat &work, Mat &result, float distribution_b[], float distribution_g[], float distribution_r[])
//{
//	float b[256] = { 0 }, g[256] = { 0 }, r[256] = { 0 };
//	statistics(work, b, g, r);
//	//������b,g,r,distribution_b,distribution_g,distribution_r�����ۻ�
//	for (int i = 1; i < 256; i++)
//	{
//		b[i] += b[i - 1];
//		g[i] += g[i - 1];
//		r[i] += r[i - 1];
//		distribution_b[i] += distribution_b[i - 1];
//		distribution_g[i] += distribution_g[i - 1];
//		distribution_r[i] += distribution_r[i - 1];
//	}
//	unsigned int map_b[256], map_g[256], map_r[256];	//�涨�����ӳ���ϵ
//	for (int i = 0; i < 256; i++)
//	{
//		float diff_b = 666, diff_g = 666, diff_r = 666;		//�����ľ���ֵ����Сֵ, ��ʼֵֻҪ����1���ɡ�
//		int index_b = -1, index_g = -1, index_r = -1;		//����ľ���ֵȡ����Сֵʱ��Ӧ������
//		for (int j = 0; j < 256; j++)
//		{
//			float diff = abs(b[i] - distribution_b[j]);
//			if (diff < diff_b)
//			{
//				diff_b = diff;
//				index_b = j;
//			}
//
//			diff = abs(g[i] - distribution_g[j]);
//			if (diff < diff_g)
//			{
//				diff_g = diff;
//				index_g = j;
//			}
//			diff = abs(r[i] - distribution_r[j]);
//			if (diff < diff_r)
//			{
//				diff_r = diff;
//				index_r = j;
//			}
//		}
//		map_b[i] = index_b;
//		map_g[i] = index_g;
//		map_r[i] = index_r;
//	}
//	result = work.clone();
//	Mat_<Vec3b>::iterator it_begin = result.begin<Vec3b>();
//	Mat_<Vec3b>::iterator it_end = result.end<Vec3b>();
//	for (Mat_<Vec3b>::iterator it = it_begin; it != it_end; it++)
//	{
//		(*it)[0] = map_b[(*it)[0]];
//		(*it)[1] = map_g[(*it)[1]];
//		(*it)[2] = map_r[(*it)[2]];
//	}
//}
//int main()
//{
//	Mat image = imread("f:\\ͼƬ\\lenna.jpg");		//�任ǰͼ��
//	Mat reference = imread("f:\\ͼƬ\\С����.jpg");		//���ڲ����涨ֱ��ͼ
//	float b[256] = { 0 }, g[256] = { 0 }, r[256] = { 0 };
//	statistics(reference, b, g, r);
//	Mat result = image.clone();
//	specification(image, result, b, g, r);
//
//	namedWindow("ԭͼ��", 0);
//	resizeWindow("ԭͼ��", 500, 500);
//	namedWindow("�涨����", 0);
//	resizeWindow("�涨����", 500, 500);
//	namedWindow("�涨ֱ��ͼ", 0);
//	resizeWindow("�涨ֱ��ͼ", 500, 500);
//	imshow("ԭͼ��", image);
//	imshow("�涨ֱ��ͼ", reference);
//	imshow("�涨����", result);
//	waitKey(0);
//	return 0;
//}