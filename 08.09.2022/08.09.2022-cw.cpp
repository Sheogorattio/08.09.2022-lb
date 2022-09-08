#include <iostream>
using namespace std;

class Car
{
	char* model;
	char* country;
	double price;
	static int count;
public:
	Car();
	Car(const char* m, const char* c, double p);
	~Car();
	void Input();
	void Print();
	const char* GetModel();
	void SetModel(const char* m);
	const char* GetCountry();
	void SetCountry(const char* c);

	//  static method
	static int GetCount();
	static void DecrCount();

};
int Car::count = 0;



int main()
{
	int count;
	cin >> count;
	cin.get();
	Car* shop = new Car[count];
	for (int i = 0; i < count; i++) {
		shop[i].Input();
	}
	for (int i = 0; i < count; i++) {
		shop[i].Print();
	}
	cout << "total number of vehicles: " << Car::GetCount();
	// ввод, вывод, вывод кол-во автомобилей!

}

Car::Car()
{
	model = nullptr;
	country = nullptr;
	price = 0.0;
	count++;
}

Car::Car(const char* m, const char* c, double p)
{
	model = new char(strlen(m) + 1);
	strcpy_s(model, strlen(m) + 1, m);
	country = new char[strlen(c) + 1];
	strcpy_s(country, strlen(c) + 1, c);
	price = p;
	count++;
}

Car::~Car()
{
	delete[] model;
	delete[]country;
}

void Car::Input()
{
	char buff_m[255];
	cout << "enter model\n";
	if (model != nullptr) {
		delete[] model;
	}
	cin.getline(buff_m, 255);
	model = new char[strlen(buff_m + 1)];
	strcpy_s(model, strlen(buff_m) + 1, buff_m);
	char buff_c[255];
	cout << "enter country\n";
	cin.getline(buff_c, 255);
	if (country != nullptr) {
		delete[] country;
	}
	country = new char[strlen(buff_c) + 1];
	strcpy_s(country, strlen(buff_c) + 1, buff_c);
	double p;
	cout << "enter price: ";
	cin >> p;
	cin.get();
	price = p;
}

void Car::Print()
{
	system("cls");
	cout << "model: " << model << endl;
	cout << "country: " << country << endl;
	cout << "price: " << price << endl;
	cout << "-------------------\n";
}

const char* Car::GetModel()
{
	return model;
}

void Car::SetModel(const char* m)
{
	if (model != nullptr) {
		delete[] model;
	}
	model = new char[strlen(m) + 1];
	strcpy_s(model, strlen(m) + 1, m);
}

const char* Car::GetCountry()
{
	return country;
}

void Car::SetCountry(const char* c)
{
	if (country != nullptr) {
		delete[] country;
	}
	country = new char[strlen(c) + 1];
	strcpy_s(country, strlen(c) + 1, c);
}

int Car::GetCount()
{
	return count;
}

void Car::DecrCount()
{
	count--;
}
