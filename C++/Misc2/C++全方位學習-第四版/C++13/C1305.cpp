//檔案名稱：d:\C++13\C1305.cpp
#include <iostream>
using namespace std;

class Base		//定義基礎類別Base
{
public:
	Base() {cout << "建立基礎類別\n";}
	~Base() {cout << "破壞基礎類別\n";}
};

class Derived: public Base	//Derived繼承Base類別
{
public:
	Derived() {cout << "建立衍生類別\n";}
	~Derived() {cout << "破壞衍生類別\n";}
};

int main(int argc, char** argv)
{
	Derived d;	//建立Derived物件
	system("PAUSE");
	return 0;
}
