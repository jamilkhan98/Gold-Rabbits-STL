//Jamil Khan
//CECS 282 - 05
//Prog 5 - Standard Template Library (STL)
//Nov. 27, 2018

#include <algorithm>
#include <vector>
#include <iostream>
#include <random>
#include <string>

using namespace std;

#ifndef BIG_INT_H
#define BIG_INT_H
class BigInt {
private:
	vector<int> d;
public:
	BigInt();
	BigInt(int);
	BigInt(string);
	BigInt operator+(BigInt);
	friend ostream & operator<<(ostream &, const BigInt &);
};
#endif


