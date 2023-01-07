//檔案名稱：d:\C++14\C1408.cpp
#include <iostream>
using namespace std;

class Base	//定義抽象Base類別
{
public:
	virtual void show() = 0;	//宣告存虛擬函數show
};

class Derived1: public Base	//繼承Base抽象類別
{
public:
	void show() {	//實現show函數
		cout << "衍生類別1\n";
	}
};

class Derived2: public Base
{
public:
	void show() {	//實現show函數
		cout << "衍生類別2\n";
	}
};

int main(int argc, char** argv)
{
	Base *list[2];
	Derived1 d1;
	Derived2 d2;
	list[0] = &d1;	//指標[0]指向d1
	list[1] = &d2; 	//指標[1]指向d2
	list[0]->show();	//顯示"衍生類別1"
	list[1]->show();	//顯示"衍生類別2"
	return 0;
}
