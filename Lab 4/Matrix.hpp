/*
 * Matrix.hpp
 *
 *  Created on: Oct 11, 2017
 *      Author: Michael Ly
 */

#include <iostream>
#include <stdlib.h>
#include <string>
#include <math.h>
using namespace std;

#ifndef MATRIX_HPP_
#define MATRIX_HPP_

class Matrix {

private:
	char** matrix;
	int length;
	int width;

public:
	Matrix(); // Constructor
	char** createMatrixAdd(); // Method
	void printMatrix(); // Method
	void fillMatrix(); // Method
	~Matrix(); // Destructor

};



#endif /* MATRIX_HPP_ */
