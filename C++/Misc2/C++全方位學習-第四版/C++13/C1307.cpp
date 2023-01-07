//檔案名稱：d:\C++13\C1307.cpp
#include <iostream>
using namespace std;

class Base1		//定義基礎類別Base1
{
public:
	Base1() {cout << "建立基礎類別1\n";}
	~Base1() {cout << "破壞基礎類別1\n";}
};

class Base2		//定義基礎類別Base2
{
public:
	Base2() {cout << "建立基礎類別2\n";}
	~Base2() {cout << "破壞基礎類別2\n";}
};

class Derived: public Base1, public Base2	//繼承Base1與Base2
{
public:
	Derived() {cout << "建立衍生類別\n";}
	~Derived() {cout << "破壞衍生類別\n";}
};

int main(int argc, char** argv)
{
	Derived d;	//建立Derived物件d
	system("PAUSE");
	return 0;
}
