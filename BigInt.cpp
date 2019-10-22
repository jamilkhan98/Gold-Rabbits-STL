//Jamil Khan
//CECS 282 - 05
//Prog 5 - Standard Template Library
//Nov. 27, 2018

#include "BigInt.h"
#include <string>
#include <iostream>
#include <vector>

using namespace std;

BigInt::BigInt() {
	d.push_back(0);
}

BigInt::BigInt(int n) {
	if (n == 0) {
		d.push_back(0);
	}
	while (n!=0) {
		d.push_back(n%10);
		n /= 10;
	}
}

BigInt::BigInt(string s) {
	string::iterator sit;
	for (sit = s.end(); sit != s.begin(); sit--) {
		int number = *sit - 48;
		d.push_back(number);
	}

}

BigInt BigInt::operator+(BigInt B) {
	BigInt temp(*this);
	while (B.d.size() != temp.d.size()) {
		if (B.d.size() > temp.d.size()) {
			temp.d.push_back(0);
		}
		else {
			B.d.push_back(0);
		}
	}
	int carry = 0;
	for (int i = 0; i < temp.d.size(); i++) {
		if (carry == 1) {
			temp.d[i] += 1;
			carry = 0;
		}
		if (temp.d[i] + B.d[i] >= 10) {
			carry = 1;
		}
		temp.d[i] += B.d[i] - carry * 10;
	}
	if (carry == 1) {
		temp.d.push_back(1);
	}
	return temp;
}

ostream & operator<<(ostream & os, const BigInt & B) {
	vector<int> b = B.d;
	vector<int>::reverse_iterator rit = b.rbegin();
	while (rit != b.rend()) {
		os << *rit;
		rit++;
	}
	return os;
}

