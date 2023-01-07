//檔案名稱：d:\C++13\C1306.cpp
#include <iostream>
using namespace std;

class Base		//定義基礎類別Base
{
public:
	Base() {cout << "建立基礎類別\n";}
	~Base() {cout << "破壞基礎類別\n";}
};

class Derived1: public Base	//Derived1繼承Base
{
public:
	Derived1() {cout << "建立衍生類別\n";}
	~Derived1() {cout << "破壞衍生類別\n";}
};

class Derived2: public Derived1                    //Derived2繼承Derived1
{
public:
	Derived2() {cout << "建立衍生類別2\n";}
	~Derived2() {cout << "破壞衍生類別2\n";}
};

int main(int argc, char** argv)
{
	Derived2 d; 	//建立Derived2物件
	system("PAUSE");
	return 0;
}
