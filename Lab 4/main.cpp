/*
 * main.cpp
 *
 *  Created on: Oct 8, 2017
 *      Author: Michael Ly
 */

/* Michael Ly
 * TA: Eeshita Biswas
 * 10/8/17
 * Lab 4
 * This file contains functions for Lab 4.
 */

#include <iostream>
#include <stdlib.h>
#include <string>
#include <math.h>
#include "HexNum.hpp"
#include "Matrix.hpp"
using namespace std;

// Function Declarations
string gibberish(string str, int& len);
/* Returns a new string with "ithag" concatenated to each vowel character of the input string.
 * Parameters: str: input string.
 * 			   &len: the length of the input string, passed by reference.
 */

int hexToDeci(string hex, int pos, int result);
/* Converts a hexadecimal number to a decimal number.
 * Parameters: hex: the input hexadecimal number as a string.
 *             pos: the index position within the string, initialized by 0.
 *             result: the final result after conversion, initialized by 0.
 */

string DeciToHex(int deci, string result);
/* Converts a decimal number to a hexadecimal number.
 * Parameters: deci: the input decimal number as an integer.
 *             result: the final result after conversion, initialized by an empty string.
 */

char** createMatrixAdd(int* row, int* column);
/* Creates a matrix filled with 0 and prints out the address of the matrix.
 * Parameters: *row: the input number of rows in the matrix created.
 * 			   *column: the input number of columns in the matrix created.
 */

void printMatrix(char** matrix, int row, int column);
/* Prints out the matrix passed in with the row and column of that matrix.
 * Parameters: **matrix: a matrix as an input.
 *             row: the number of rows of the matrix as an input.
 *             column: the number of columns of the matrix as an input.
 */

void fillMatrix(char** matrix, int row, int column);
/* Replacing '0's in the input matrix with 'x's in 5 random spots.
 * Parameters: **matrix: a matrix as an input.
 *             row: the number of rows of the matrix as an input.
 *             column: the number of columns of the matrix as an input.
 */

char** createXMatrix(char** matrix, int row, int column);
/* Creates a matrix filled with x in 5 random spots of the matrix and 0 filled in the rest of the spots.
 * Parameters: **matrix: a matrix as an input.
 *             row: the number of rows of the matrix as an input.
 *             column: the number of columns of the matrix as an input.
 */

// Test Cases
int main() {

	cout << "Problem 1" << endl;
	cout << "Test 1: " << endl;
	int len1 = 3;
	cout << gibberish("Cat", len1) << endl; // Expected output is "cithagat".
	cout << "New length of the string: " << gibberish("Cat", len1).length() << endl; // Expected output is 8.
	cout << endl;
	cout << "Test 2: " << endl;
	int len2 = 5;
	cout << gibberish("cover", len2) << endl; // Expected output is "cithagovithager".
	cout << "New length of the string: " << gibberish("cover", len2).length() << endl; // Expected output is 15.
	cout << endl;
	cout << "Test 3: " << endl;
	int len3 = 5;
	cout << gibberish("Array", len3) << endl; // Expected output is "ithagarrithagaithagy".
	cout << "New length of the string: " << gibberish("Array", len3).length() << endl; // Expected output is 20.
	cout << "************************************" << endl;

	cout << "Problem 2" << endl;
	cout << "Test 1: " << endl;
	cout << hexToDeci("5098", 0, 0) << endl; // Expected output is 20632.
	cout << "Test 2: " << endl;
	cout << hexToDeci("AF94587", 0, 0) << endl; // Expected output is 184108423.
	cout << "Test 3: " << endl;
	cout << hexToDeci("F4AC", 0, 0) << endl; // Expected output is 62636.
	cout << "************************************" << endl;

	cout << "Problem 3" << endl;
	cout << "Test 1: " << endl;
	cout << DeciToHex(16, "") << endl; // Expected output is 10.
	cout << "Test 2: " << endl;
	cout << DeciToHex(20632, "") << endl; // Expected output is 5098.
	cout << "Test 3: " << endl;
	cout << DeciToHex(62636, "") << endl; // Expected output is F4AC.
	cout << "************************************" << endl;

	cout << "Problem 4" << endl;
	cout << "Test 1:" << endl;
	HexNum hn1 = HexNum(14);
	cout << "The integer form of hn1 is: " << hn1.getInt() << endl; // Expected output is 14.
	cout << "The hexadecimal form of hn1 is: " << hn1.getHex() << endl; // Expected output is E.
	cout << endl;
	cout << "Test 2:" << endl;
	HexNum hn2 = HexNum(20632);
	cout << "The integer form of hn2 is: " << hn2.getInt() << endl; // Expected output is 20632.
	cout << "The hexadecimal form of hn2 is: " << hn2.getHex() << endl; // Expected output is 5098.
	cout << endl;
	cout << "Test 3:" << endl;
	HexNum hn3 = HexNum(456);
	cout << "The integer form of hn3 is: " << hn3.getInt() << endl; // Expected output is 456.
	cout << "The hexadecimal form of hn3 is: " << hn3.getHex() << endl; // Expected output is 1C8.
	cout << endl;
	cout << "Test 4:" << endl;
	HexNum hn4 = HexNum("F4AC");
	cout << "The integer form of hn4 is: " << hn4.getInt() << endl; // Expected output is 62636.
	cout << "The hexadecimal form of hn4 is: " << hn4.getHex() << endl; // Expected output is F4AC.
	cout << endl;
	cout << "Test 5:" << endl;
	HexNum hn5 = HexNum("5B");
	cout << "The integer form of hn5 is: " << hn5.getInt() << endl; // Expected output is 91.
	cout << "The hexadecimal form of hn5 is: " << hn5.getHex() << endl; // Expected output is 5B.
	cout << endl;
	cout << "Test 6" << endl;
	HexNum hn6 = HexNum("2EF5");
	cout << "The integer form of hn6 is: " << hn6.getInt() << endl; // Expected output is 12021.
	cout << "The hexadecimal form of hn6 is: " << hn6.getHex() << endl; // Expected output is 2EF5.
	cout << "************************************" << endl;

	cout << "Problem 5a" << endl;
	cout << "Test 1: " << endl;
	int row1, column1;
	char** mat1;
	mat1 = createMatrixAdd(&row1, &column1);
	cout << "The address of mat1: " << mat1 << endl; // Expected the address of the matrix with dimension of row1*column1;
	cout << "row1 = " << row1 << endl; // Expected a random integer between 3 and 10.
	cout << "column1 = " << column1 << endl; // Expected a random integer between 3 and 10.
	cout << endl;
	cout << "Test 2: " << endl;
	int row2, column2;
	char** mat2;
	mat2 = createMatrixAdd(&row2, &column2);
	cout << "The address of mat2: " << mat2 << endl; // Expected the address of the matrix with dimension of row2*column2;
	cout << "row2 = " << row2 << endl; // Expected a random integer between 3 and 10.
	cout << "column2 = " << column2 << endl; // Expected a random integer between 3 and 10.
	cout << endl;
	cout << "Test 3: " << endl;
	int row3, column3;
	char** mat3;
	mat3 = createMatrixAdd(&row3, &column3);
	cout << "The address of mat3: " << mat3 << endl; // Expected the address of the matrix with dimension of row3*column3;
	cout << "row3 = " << row3 << endl; // Expected a random integer between 3 and 10.
	cout << "column3 = " << column3 << endl; // Expected a random integer between 3 and 10.
	cout << "************************************" << endl;

	cout << "Problem 5b" << endl;
	cout << "Test 1:" << endl;
	printMatrix(mat1, row1, column1); // Expected mat1 to be printed out.
	cout << endl;
	cout << "Test 2:" << endl;
	printMatrix(mat2, row2, column2); // Expected mat2 to be printed out.
	cout << endl;
	cout << "Test 3:" << endl;
	printMatrix(mat3, row3, column3); // Expected mat3 to be printed out.
	cout << "************************************" << endl;

	cout << "Problem 5c & 5d" << endl;
	cout << "Test 1:" << endl;
	char** matwX1;
	matwX1 = createXMatrix(mat1, row1, column1);
	printMatrix(matwX1, row1, column1); // Expected mat1 to be printed out along with x replacing 0 in 5 random spots.
	cout << endl;
	cout << "Test 2:" << endl;
	char** matwX2;
	matwX2 = createXMatrix(mat2, row2, column2);
	printMatrix(matwX2, row2, column2); // Expected mat2 to be printed out along with x replacing 0 in 5 random spots.
	cout << endl;
	cout << "Test 3:" << endl;
	char** matwX3;
	matwX3 = createXMatrix(mat3, row3, column3);
	printMatrix(matwX3, row3, column3); // Expected mat3 to be printed out along with x replacing 0 in 5 random spots.
	cout << "************************************" << endl;

	cout << "Problem 6" << endl;
	cout << "Test 1:" << endl;
	Matrix cmat1 = Matrix();
	cout << cmat1.createMatrixAdd() << endl; // Expected an address to be printed out.
	cout << endl;
	cout << "cmat1 with 0: " << endl;
	cmat1.printMatrix(); // Expected the matrix filled with 0 be printed out.
	cout << endl;
	cmat1.fillMatrix();
	cout << "cmat1 with x: " << endl;
	cmat1.printMatrix(); // Expected the matrix with 5 "x"s.
	cout << endl;
	cout << "Test 2:" << endl;
	Matrix cmat2 = Matrix();
	cout << cmat2.createMatrixAdd() << endl; // Expected an address to be printed out.
	cout << endl;
	cout << "cmat2 with 0: " << endl;
	cmat2.printMatrix(); // Expected the matrix filled with 0 be printed out.
	cout << endl;
	cmat2.fillMatrix();
	cout << "cmat2 with x: " << endl;
	cmat2.printMatrix(); // Expected the matrix with 5 "x"s.
	cout << endl;
	cout << "Test 3:" << endl;
	Matrix cmat3 = Matrix();
	cout << cmat3.createMatrixAdd() << endl; // Expected an address to be printed out.
	cout << endl;
	cout << "cmat3 with 0: " << endl;
	cmat3.printMatrix(); // Expected the matrix filled with 0 be printed out.
	cout << endl;
	cmat3.fillMatrix();
	cout << "cmat3 with x: " << endl;
	cmat3.printMatrix(); // Expected the matrix with 5 "x"s.

	return 0;
}

// Problem 1
string gibberish(string str, int& len) {
	string result = "";
	for (int i=0; i<len; i++) {
		if (str[i]=='a' || str[i]=='e' || str[i]=='i' || str[i]=='o' || str[i]=='u' || str[i]=='y') {
			result += "ithag" + string(1, str[i]);
		}
		else if (str[i]=='A' || str[i]=='E' || str[i]=='I' || str[i]=='O' || str[i]=='U' || str[i]=='Y') {
			result += "ithag" + string(1, tolower(str[i]));
		}
		else if (isupper(str[i])){
			result += string(1, tolower(str[i]));
		}
		else {
			result += string(1, str[i]);
		}
	}
	return result;
}

// Problem 2
int hexToDeci(string hex, int pos, int result) {
	if (pos == hex.length()) {
		return result;
	}
	else if (hex[pos] == '1') {
		return hexToDeci(hex, pos+1, result + 1*pow(16, hex.length()-1-pos));
	}
	else if (hex[pos] == '2') {
		return hexToDeci(hex, pos+1, result + 2*pow(16, hex.length()-1-pos));
	}
	else if (hex[pos] == '3') {
		return hexToDeci(hex, pos+1, result + 3*pow(16, hex.length()-1-pos));
	}
	else if (hex[pos] == '4') {
		return hexToDeci(hex, pos+1, result + 4*pow(16, hex.length()-1-pos));
	}
	else if (hex[pos] == '5') {
		return hexToDeci(hex, pos+1, result + 5*pow(16, hex.length()-1-pos));
	}
	else if (hex[pos] == '6') {
		return hexToDeci(hex, pos+1, result + 6*pow(16, hex.length()-1-pos));
	}
	else if (hex[pos] == '7') {
		return hexToDeci(hex, pos+1, result + 7*pow(16, hex.length()-1-pos));
	}
	else if (hex[pos] == '8') {
		return hexToDeci(hex, pos+1, result + 8*pow(16, hex.length()-1-pos));
	}
	else if (hex[pos] == '9') {
		return hexToDeci(hex, pos+1, result + 9*pow(16, hex.length()-1-pos));
	}
	else if (hex[pos] == 'A') {
		return hexToDeci(hex, pos+1, result + 10*pow(16, hex.length()-1-pos));
	}
	else if (hex[pos] == 'B') {
		return hexToDeci(hex, pos+1, result + 11*pow(16, hex.length()-1-pos));
	}
	else if (hex[pos] == 'C') {
		return hexToDeci(hex, pos+1, result + 12*pow(16, hex.length()-1-pos));
	}
	else if (hex[pos] == 'D') {
		return hexToDeci(hex, pos+1, result + 13*pow(16, hex.length()-1-pos));
	}
	else if (hex[pos] == 'E') {
		return hexToDeci(hex, pos+1, result + 14*pow(16, hex.length()-1-pos));
	}
	else if (hex[pos] == 'F') {
		return hexToDeci(hex, pos+1, result + 15*pow(16, hex.length()-1-pos));
	}
	else {
		return hexToDeci(hex, pos+1, result + 0*pow(16, hex.length()-1-pos));
	}
}

// Problem 3
string DeciToHex(int deci, string result) {
	if (deci%16 == 1) {
		result = "1"+result;
	}
	else if (deci%16 == 2) {
		result = "2"+result;
	}
	else if (deci%16 == 3) {
		result = "3"+result;
	}
	else if (deci%16 == 4) {
		result = "4"+result;
	}
	else if (deci%16 == 5) {
		result = "5"+result;
	}
	else if (deci%16 == 6) {
		result = "6"+result;
	}
	else if (deci%16 == 7) {
		result = "7"+result;
	}
	else if (deci%16 == 8) {
		result = "8"+result;
	}
	else if (deci%16 == 9) {
		result = "9"+result;
	}
	else if (deci%16 == 10) {
		result = "A"+result;
	}
	else if (deci%16 == 11) {
		result = "B"+result;
	}
	else if (deci%16 == 12) {
		result = "C"+result;
	}
	else if (deci%16 == 13) {
		result = "D"+result;
	}
	else if (deci%16 == 14) {
		result = "E"+result;
	}
	else if (deci%16 == 15) {
		result = "F"+result;
	}
	else {
		result = "0"+result;
	}

	if (deci/16 == 0) {
		return result;
	}
	else {
		return DeciToHex(deci/16, result);
	}
}

// Problem 5
char** createMatrixAdd(int* row, int* column) {
	*row = rand()%7 + 3;
	*column = rand()%7 + 3;
	char** mat = new char*[*row];
	for (int i=0; i<*row; i++) {
		mat[i] = new char[*column];
		for (int j=0; j<*column; j++) {
			mat[i][j] = '0';
		}
	}
	return mat;
	for (int i=0; i<*row; i++) {
		delete[] mat[i];
	}
	delete[] mat;
}

// Problem 5b
void printMatrix(char** matrix, int row, int column) {
	for (int i=0; i<row; i++) {
		for (int j=0; j<column; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}

// Problem 5c
void fillMatrix(char** matrix, int row, int column) {
	for (int i=0; i<5; i++) {
		start:
		int x = rand()%row;
		int y = rand()%column;
		if (matrix[x][y] == '0') {
			matrix[x][y] = 'x';
		}
		else {
			goto start;
		}
	}
}

char** createXMatrix(char** matrix, int row, int column) {
	char** matwX = new char*[row];
	for (int i=0; i<row; i++) {
		matwX[i] = new char[column];
		for (int j=0; j<column; j++) {
			matwX[i][j] = '0';
		}
	}
	fillMatrix(matwX, row, column);
	return matwX;
	for (int l=0; l<row; l++) {
		delete[] matwX[l];
	}
	delete[] matwX;
}

