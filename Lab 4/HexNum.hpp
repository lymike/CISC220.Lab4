/*
 * HexNum.hpp
 *
 *  Created on: Oct 11, 2017
 *      Author: Michael Ly
 */

#include <iostream>
#include <stdlib.h>
#include <string>
#include <math.h>
using namespace std;

#ifndef HEXNUM_HPP_
#define HEXNUM_HPP_

class HexNum {

private:
	int integer;
	string hex;

public:
	HexNum(int n); // Constructor
	HexNum(string h); // Constructor
	string DeciToHex(int deci, string result); // Method
	int hexToDeci(string hex, int pos, int result); // Method
	int getInt(); // Getter
	string getHex(); // Getter
	void setInt(int n); // Setter
	void setHex(string h); // Setter

};



#endif /* HEXNUM_HPP_ */
