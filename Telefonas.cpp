/**
 * @author Arturas Timofejevas (@Rave1s), VU SE 2 course 2 group
 */

#include <iostream>
#include <sstream>
#include <cassert>

using namespace std;

class Phone {
	

private:
	static int phoneCount;
	static int phoneIDCount;
	string brand;
	string model;
	double price;
	int phoneID;
	int numOfCalls;

public:
	~Phone() {
		phoneCount--;
	}

	Phone(string brand, string model, double price) {
		setBrand(brand);
		setModel(model);
		setPrice(price);
		phoneCount++;
		phoneID = phoneIDCount;
		phoneIDCount++;
		numOfCalls = 0;
	}

	Phone(string model, double price) {
		setModel(model);
		setPrice(price);
		phoneCount++;
		phoneID = phoneIDCount;
		phoneIDCount++;
		numOfCalls = 0;
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

	void setPrice(double price) {
		if (price >= 0.0) {
			this->price = price;
		}
		else {
			throw price;
		}
	}
	double getPrice() const {
		return price;
	}

	static int getPhoneCount() {
		return phoneCount;
	}
	int getPhoneID() const {
		return phoneID;
	}

	void call() {
		cout << "You called someone using the " << getModel() << endl;
		numOfCalls++;
	}
	int getNumberOfCalls() const {
		return numOfCalls;
	}

	string toString() const {
		ostringstream phoneData;
		phoneData << "Here is the info about this phone: \n" << "Brand: " << getBrand() << "\nModel: " << getModel() << "\nPrice: " << getPrice() << "\nPhone ID: " << getPhoneID() << "\nNumber of calls made with this phone: " << getNumberOfCalls();
		return phoneData.str();
	}
};

int Phone::phoneCount = 0;
int Phone::phoneIDCount = 0;

int main() {
	assert(Phone::getPhoneCount() == 0);
	cout << "Initial phone count correct" << endl;

	try {
		Phone phone("zPhone 1", 199.99);

		assert(phone.getModel() == "zPhone 1");
		assert(phone.getPrice() == 199.99);
		assert(phone.getPhoneCount() == 1);
		assert(phone.getPhoneID() == 0);
		assert(phone.getNumberOfCalls() == 0);
		cout << "Constructor check passed" << endl;
		cout << phone.toString() << endl;


		phone.setBrand("Pear");
		assert(phone.getBrand() == "Pear");

		phone.setModel("zPhone");
		assert(phone.getModel() == "zPhone");

		phone.setPrice(249.99);
		assert(phone.getPrice() == 249.99);
		cout << "Phone attribute setter and getter check passed" << endl;
		
		for (int i = 0; i < 3; i++) {
			phone.call();
		}
		assert(phone.getNumberOfCalls() == 3);
		cout << "Call method works" << endl;
		cout << phone.toString() << endl;


		const int testArray = 10;

		Phone* zphones[testArray];
		for (int i = 0; i < testArray; i++) {
			zphones[i] = new Phone("Pear", "zPhone " + to_string(i + 2),	299.99 + (i * 50.00));
			zphones[i]->call();
		}

		assert(zphones[2]->getModel() == "zPhone 4");
		assert(zphones[6]->getPrice() == 599.99);
		assert(zphones[9]->getModel() == "zPhone 11");
		assert(zphones[7]->getNumberOfCalls() == 1);
		cout << "zPhone list created and filled correctly" << endl;

		assert(Phone::getPhoneCount() == 11);
		cout << "Object count is correct" << endl;

		assert(phone.getPhoneID() == 0);
		assert(zphones[3]->getPhoneID() == 4);
		assert(zphones[9]->getPhoneID() == 10);
		cout << "IDs assigned correctly" << endl;

		cout << zphones[2]->toString() << endl;
		cout << zphones[8]->toString() << endl;

		for (int i = 0; i < testArray; i++) {
			delete zphones[i];
		}
		assert(Phone::getPhoneCount() == 1);
		cout << "Object count after deletion correct" << endl;
	}
	catch (string& model) {
		cout << "Phone's model must be provided" << endl;
	}
	catch (int price) {
		cout << "Price cannot be negative" << endl;
	}

	assert(Phone::getPhoneCount() == 0);
	cout << "Object count upon deletion is correct" << endl;

	return 0;
}