//檔案名稱：d:\C++14\C1406.cpp
#include <iostream>
using namespace std;

class Base
{
public:
	virtual void show() {cout << "基礎類別\n";};	//宣告Base::show()
};

class Derived1: public Base
{
public:
	void show() {cout << "衍生類別1\n";}	//宣告Derived1::show()
};

class Derived2: public Base
{
public:
	void show() {cout << "衍生類別2\n";} 	//宣告Derived2::show()
};

int main(int argc, char** argv)
{
	Base b;
	Derived1 d1;
	Derived2 d2;
	Base *ptr;
	ptr = &b;	//指標ptr指向b
	ptr->show();	//顯示"基礎類別"
	ptr = &d1;	//指標ptr指向d1
	ptr->show();	//顯示"衍生類別1"
	ptr = &d2; 	//指標ptr指向d2
	ptr->show();	//顯示"衍生類別2"
	return 0;
}
