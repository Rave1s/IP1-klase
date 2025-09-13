#include <iostream>
#include <sstream>
#include <cassert>

using namespace std;

class Phone {
	static int phoneCount;
	static int phoneIDCount;

private:
	string brand;
	string model;
	int price;
	int phoneID;

public:
	~Phone() {

	}

	Phone(string brand, string model, int price) {

	}

	Phone(string model, int price) {

	}

};

int main() {
	return 0;
}