/*
 * HexNum.cpp
 *
 *  Created on: Oct 11, 2017
 *      Author: Michael Ly
 */

#include "HexNum.hpp"
#include <string>
#include <math.h>
using namespace std;

HexNum::HexNum(int n) {
	integer = n;
	hex = DeciToHex(n, "");
}

HexNum::HexNum(string h) {
	integer = hexToDeci(h, 0, 0);
	hex = h;
}

string HexNum::DeciToHex(int deci, string result) {
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

int HexNum::hexToDeci(string hex, int pos, int result) {
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

int HexNum::getInt() {
	return integer;
}

string HexNum::getHex() {
	return hex;
}

void HexNum::setInt(int n) {
	integer = n;
}

void HexNum::setHex(string h) {
	hex = h;
}
