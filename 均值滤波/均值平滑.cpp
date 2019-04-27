#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
using namespace std;
using namespace cv;
//at��������ͼ��m��λ��(i,j)�����صģ�flag=0,1,2�ֱ��ʾ����b,g,rͨ��,
//�����ʱ߽�֮������ʱ�����ø��Ʊ߽����صķ�����
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
//��ͼ�������ص�(i, j)��3*3������ģ����ˣ������������product�У�templet��ģ��
void multiply(Mat &m, int i, int j, float templet[3][3], float product[3])
{
	for (int k = 0; k < 3; k++) //k��ʾ����ͨ��
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
			float product[3]; //product[0]��bͨ����ģ��ĳ˻���/product[1]��gͨ����ģ��ĳ˻���/product[2]��rͨ����ģ��ĳ˻���
			multiply(src, i, j, templet, product);
			for (int k = 0; k < 3; k++)
				dst.at<Vec3b>(i, j)[k] = product[k];
		}
	}
}
int main()
{

	Mat image = imread("f:\\ͼƬ\\lenna.jpg");		//�任ǰͼ��
	Mat result = image.clone();
	mean_filter(image, result);
	namedWindow("ԭͼ��", 0);
	resizeWindow("ԭͼ��", 500, 500);
	namedWindow("��ֵ�˲�", 0);
	resizeWindow("��ֵ�˲�", 500, 500);
	imshow("ԭͼ��", image);
	imshow("��ֵ�˲�", result);
	waitKey(0);
	return 0;
}