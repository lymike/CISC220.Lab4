/*
 * Matrix.cpp
 *
 *  Created on: Oct 11, 2017
 *      Author: Michael Ly
 */

#include <iostream>
#include <stdlib.h>
#include <string>
#include <math.h>
#include "Matrix.hpp"
using namespace std;

Matrix::Matrix() {
	matrix = NULL;
	length = 0; // row
	width = 0; // column
}

char** Matrix::createMatrixAdd() {
	length = rand()%7 + 3;
	width = rand()%7 + 3;
	matrix = new char*[length];
	for (int i=0; i<length; i++) {
		matrix[i] = new char[width];
		for (int j=0; j<width; j++) {
			matrix[i][j] = '0';
		}
	}
	return matrix;
}

void Matrix::printMatrix() {
	for (int i=0; i<length; i++) {
		for (int j=0; j<width; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}

void Matrix::fillMatrix() {
	for (int i=0; i<5; i++) {
		start:
		int x = rand()%length;
		int y = rand()%width;
		if (matrix[x][y] == '0') {
			matrix[x][y] = 'x';
		}
		else {
			goto start;
		}
	}
}

Matrix::~Matrix() {
	for (int i=0; i<length; i++) {
		delete[] matrix[i];
	}
	delete[] matrix;
}
