//檔案名稱：d:\C++14\C1402.cpp
#include <iostream>
using namespace std;

class Base	//宣告基礎類別
{
private:
	int a, b;
public:
	Base(int l, int m) {	//基礎類別建立者
		a = l; b = m;
	}
	void show() {	//基礎類別方法
		cout << "a = " << a << endl;
		cout << "b = " << b << endl;
	}
};

class Derived: public Base	//宣告衍生類別
{
private:
	int c;
public:
	Derived(int l, int m, int n): Base(l, m) {	//衍生類別建立者
		c = n;
	}
	void show() {	//衍生類別超載方法
		Base::show();
		cout << "c = " << c << endl;
	}
};

int main(int argc, char** argv)
{
	Derived d(2, 3, 5);	//建立Derived物件d
	d.show();	//呼叫Derived多載方法
	return 0;
}
