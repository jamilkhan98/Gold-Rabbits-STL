//Jamil Khan
//CECS 282 - 05
//Prog 5 - Standard Template Library
//Nov. 27, 2018

#include "BigInt.h"
#include <string>
#include <map>
#include <iostream>
#include <vector>

using namespace std;

BigInt goldRabbits(int);
int fact(int);

int main() {
	for (int n = 0; n <= 1000; n++) {
		cout << "\nThe GoldRabbit of (" << n << ") is " << goldRabbits(n);
	}
	getchar();
	for (int i = 0; i < 100; i++) {
		try {
			cout << "Fact(" << i << "):" << fact(i) << endl;
		}
		catch (...){
			cout << "Fact(" << i << "):" << "Overflow" << endl;
		}
	}
	getchar();
}

BigInt goldRabbits(int n) {
	static map<int, BigInt> farm;
	if (n == 0 || n == 1) {
		farm[n] = BigInt(1);
	}
	else if (farm.find(n) == farm.end()){
		farm[n] = farm[n - 1] + farm[n-2];
	}
	return farm[n];
}

int fact(int n) {
	if (n == 0) {
		return 1;
	}
	if (n >= 13) {
		throw "Exception";
	}
	else {
		return n * fact(n - 1);
	}
}