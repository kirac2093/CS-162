/********************************************************
Name: ppmGen
Desc: create simple PPM file using multidimensional arrays
Code: Kira Corbett
Date: 4/7/2017
*********************************************************/

//preprocessor directives
#include <iostream>
#include <fstream>

using namespace std;

//declare constants
const int HEIGHT = 200;
const int WIDTH = 300;

const int IMAGE_START = 0;
const int IMAGE_WIDTH1 = 100;
const int IMAGE_WIDTH2 = 200;
const int IMAGE_WIDTH3 = 300;

const int PATTERN_HEIGHT = 50;
const int PATTERN_WIDTH = 100;

const int PATTERN_START = 0;
const int PATTERN_NEW_WIDTH1 = 50;
const int PATTERN_NEW_WIDTH2 = 100;
const int PATTERN_NEW_WIDTH3 = 150;
const int PATTERN_NEW_WIDTH4 = 200;
const int PATTERN_NEW_WIDTH5 = 250;
const int PATTERN_NEW_WIDTH6 = 300;

const int RED = 0;
const int GREEN = 1;
const int BLUE = 2;
const int COLOR = 3;

const int MAX_COLOR_VALUE = 255;

//function prototypes
void createImage(int rgbColor1, int rgbColor2, int rgbColor3, int imageStart, int imageWidth, static unsigned char ppmImage[][WIDTH][COLOR]);
void createGradient(static unsigned char ppmImage[][WIDTH][COLOR]);
void createPattern(static unsigned char ppmImage[][WIDTH][COLOR], int rgbColor1, int rgbColor2, int rgbColor3,
	int imageStart, int imageWidth);
void generatePPMFile(static unsigned char ppmImage[][WIDTH][COLOR]);

int main() {

	static unsigned char ppmImage[HEIGHT][WIDTH][COLOR] = {};

	//create ppm image
	createImage(0, 0, 255, IMAGE_START, IMAGE_WIDTH1, ppmImage);
	createImage(255, 255, 68, IMAGE_WIDTH1, IMAGE_WIDTH2, ppmImage);
	createImage(0, 0, 255, IMAGE_WIDTH2, IMAGE_WIDTH3, ppmImage);

	//create gradient
	createGradient(ppmImage);

	//create pattern
	createPattern(ppmImage, 68, 109, 255, PATTERN_START, PATTERN_NEW_WIDTH1);
	createPattern(ppmImage, 68, 109, 255, PATTERN_NEW_WIDTH1, PATTERN_NEW_WIDTH2);
	createPattern(ppmImage, 68, 109, 255, PATTERN_NEW_WIDTH2, PATTERN_NEW_WIDTH3);
	createPattern(ppmImage, 68, 109, 255, PATTERN_NEW_WIDTH3, PATTERN_NEW_WIDTH4);
	createPattern(ppmImage, 68, 109, 255, PATTERN_NEW_WIDTH4, PATTERN_NEW_WIDTH5);
	createPattern(ppmImage, 68, 109, 255, PATTERN_NEW_WIDTH5, PATTERN_NEW_WIDTH6);

	//generate file
	generatePPMFile(ppmImage);

	return 0;
}

/************************
Name: createImage
Desc: generates PPM image
Args: rgbColor1 (int)
rgbColor2 (int)
rgbColor3 (int)
imageStart (int)
imageWidth (int)
ppmImage (array)
Retn: void
************************/
void createImage(int rgbColor1, int rgbColor2, int rgbColor3, int imageStart, int imageWidth,
	static unsigned char ppmImage[][WIDTH][COLOR]) {
	for (int h = 0; h < HEIGHT; h++) {
		for (int w = imageStart; w < imageWidth; w++) {
			ppmImage[h][w][RED] = rgbColor1;
			ppmImage[h][w][GREEN] = rgbColor2;
			ppmImage[h][w][BLUE] = rgbColor3;
		}
	}
}

/************************************
Name: createGradient
Desc: create a gradient for PPM image
Args: ppmImage (array)
Retn: void
************************************/
void createGradient(static unsigned char ppmImage[][WIDTH][COLOR]) {
	for (int h = 0; h < HEIGHT; h++) {
		int pixColor = 0;

		for (int w = 0; w < WIDTH; w++) {
			if (w % 2 == 0) {
				pixColor += 1;
			}
			ppmImage[h][w][RED] = 255 - pixColor;
			ppmImage[h][w][BLUE] = pixColor;
		}
	}
}

/****************************************************
Name: createPattern
Desc: create a two colored rectangle in the PPM image
Args: ppmImage (array)
Retn: void
****************************************************/
void createPattern(static unsigned char ppmImage[][WIDTH][COLOR], int rgbColor1, int rgbColor2, int rgbColor3,
	int imageStart, int imageWidth) {
	int pixColor = 0;

	for (int h = 0; h < PATTERN_HEIGHT; h++) {
		for (int w = imageStart; w < imageWidth; w++) {
			if (w * PATTERN_HEIGHT > h * imageWidth) {
				ppmImage[h][w][RED] = rgbColor1;
				ppmImage[h][w][GREEN] = rgbColor2;
				ppmImage[h][w][BLUE] = rgbColor3;
			}
			else
				ppmImage[h][w][BLUE] = pixColor;
		}
	}
}

/**************************
Name: generatePPMFile
Desc: generates PPM file
Args: ppmImage (array)
Retn: void
**************************/
void generatePPMFile(static unsigned char ppmImage[][WIDTH][COLOR]) {
	ofstream outputFile;

	//open file
	outputFile.open("Kira_Corbett.ppm");

	//write data
	outputFile << "P3" << endl;
	outputFile << WIDTH << ' ' << HEIGHT << endl;
	outputFile << "255" << endl;

	for (int h = 0; h < HEIGHT; h++) {
		outputFile << endl;
		for (int w = 0; w < WIDTH; w++) {
			for (int c = 0; c < COLOR; c++) {
				outputFile << static_cast<int>(ppmImage[h][w][c]);
				outputFile << " ";
				/*outputFile << ppmImage[h][w][0] << ' ';
				outputFile << ppmImage[h][w][1] << ' ';
				outputFile << ppmImage[h][w][2] << ' ' << ' ';*/
			}
		}
	}

	//close file
	outputFile.close();
}



