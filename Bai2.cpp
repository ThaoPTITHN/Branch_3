#include <opencv2/opencv.hpp>

using namespace cv;

int main()
{

	const char* imageName = "src";
	Mat image;
	image = imread("F:/Picture/3.jpg", IMREAD_COLOR);

	if (!image.data)
	{
		printf(" No image data \n ");
		return -1;
	}

	Mat gray_image;
	cvtColor(image, gray_image, COLOR_BGR2GRAY);

	imwrite("../../images/Gray_Image.jpg", gray_image);

	namedWindow(imageName, WINDOW_AUTOSIZE);
	namedWindow("Gray image", WINDOW_AUTOSIZE);

	imshow(imageName, image);
	imshow("Gray image", gray_image);

	waitKey(0);

	return 0;
}