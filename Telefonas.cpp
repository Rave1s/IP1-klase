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
		phoneCount--;
	}

	Phone(string brand, string model, int price) {
		setBrand(brand);
		setModel(model);
		setPrice(price);
		phoneCount++;
		phoneIDCount++;
		phoneID = phoneIDCount;
	}

	Phone(string model, int price) {
		setModel(model);
		setPrice(price);
		phoneCount++;
		phoneIDCount++;
		phoneID = phoneIDCount;
	}



};

int main() {
	return 0;
}