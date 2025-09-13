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
		phoneID = phoneIDCount;
		phoneIDCount++;
	}

	Phone(string model, int price) {
		setModel(model);
		setPrice(price);
		phoneCount++;
		phoneID = phoneIDCount;
		phoneIDCount++;
	}

	void setBrand(string brand) {
		this->brand = brand;
	}
	string getBrand() const {
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
	string getModel() const {
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
	int getPrice() const {
		return price;
	}

	static int getPhoneCount() {
		return phoneCount;
	}
	int getPhoneID() const {
		return phoneID;
	}

	string toString() const {
		ostringstream phoneData;
		phoneData << "Here is the info about this phone: \n" << "Brand: " << getBrand() << "\nModel: " << getModel() << "\nPrice: " << getPrice() << "\nPhone ID: " << getPhoneID();
		return phoneData.str();
	}
};

int Phone::phoneCount = 0;
int Phone::phoneIDCount = 0;

int main() {
	try {
		Phone phone("zPhone 1", 200);

		assert(phone.getModel() == "zPhone 1");
		assert(phone.getPrice() == 200);
		assert(phone.getPhoneCount() == 1);
		assert(phone.getPhoneID() == 0);
		cout << "Constructor passed" << endl;
		cout << phone.toString() << endl;


		phone.setBrand("Pear");
		assert(phone.getBrand() == "Pear");

		phone.setModel("zPhone");
		assert(phone.getModel() == "zPhone");

		phone.setPrice(250);
		assert(phone.getPrice() == 250);
		cout << "Phone attribute setter and getter check passed" << endl;
		cout << phone.toString() << endl;
	}
	catch (string& model) {

	}
	catch (int price) {

	}

	return 0;
}