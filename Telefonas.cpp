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

	void setBrand(string brand) {
		this->brand = brand;
	}
	string getBrand() {
		return brand;
	}

	void setModel(string model) {
		if (!model.empty()) {
			this->model = model;
		}
		else {
			throw model;
		}
	}
	string getModel() {
		return model;
	}

	void setPrice(int price) {
		if (price >= 0) {
			this->price = price;
		}
		else {
			throw price;
		}
	}
	int getPrice() {
		return price;
	}

	static int getPhoneCount() {
		return phoneCount;
	}
	int getPhoneID() {
		return phoneID;
	}

	string toString() const {
		ostringstream phoneData;
		phoneData << "Here is the info about this phone: \n" << "Brand: " << getBrand() << "\n Model: " << getModel() << "\n Price: " << getPrice() << "\n Phone ID: " << getPhoneID();
		return phoneData.str();
	}
};

int Phone::phoneCount = 0;
int Phone::phoneIDCount = 0;

int main() {
	try {

	}
	catch (string& model) {

	}
	catch (int price) {

	}

	return 0;
}