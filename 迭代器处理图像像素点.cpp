//#include <iostream>  
//#include <opencv2/core/core.hpp>  
//#include <opencv2/highgui/highgui.hpp>  
//using namespace std;
//using namespace cv;
//
//void colorReduce(Mat &inputImage, Mat &outputImage, int div)
//{
//	outputImage = inputImage.clone();
//	Mat_<Vec3b>::iterator it = inputImage.begin<Vec3b>();
//	Mat_<Vec3b>::iterator itend = inputImage.end<Vec3b>();
//	Mat_<Vec3b>::iterator itout = outputImage.begin<Vec3b>();
//	for (; it != itend; it++, itout++)
//	{
//		(*itout)[0] = (*it)[0] / div * div + div / 2;
//		(*itout)[1] = (*it)[1] / div * div + div / 2;
//		(*itout)[2] = (*it)[2] / div * div + div / 2;
//	}
//}
//
//int main()
//{
//	Mat image, result1, result2,result3;
//	cout << image.size().height << " " << image.size().width << endl;
//	image = imread("f:\\Í¼Æ¬\\Ð¡°ü×Ü.jpg");
//	if (!image.data)
//	{
//		cout << "read image file fail!" << endl;
//	}
//	cout << image.channels() << endl;
//	namedWindow("Original Image");
//	imshow("Original Image", image);
//	colorReduce(image, result1, 4);
//	namedWindow("Output1 Image");
//	imshow("Output1 Image", result1);
//	colorReduce(image, result2, 16);
//	namedWindow("Output2 Image");
//	imshow("Output2 Image", result2);
//	colorReduce(image, result3, 128);
//	namedWindow("Output3 Image");
//	imshow("Output3 Image", result3);
//	waitKey(0);
//	return 0;
//}