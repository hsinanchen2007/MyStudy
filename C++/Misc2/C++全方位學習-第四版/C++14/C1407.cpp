//檔案名稱：d:\C++14\C1407.cpp
#include <iostream>
using namespace std;

class Base
{
protected:
	int i;
};

class Derived1: virtual public Base	//宣告virtual繼承Base
{
protected:
	int j;
};

class Derived2: virtual public Base	//宣告virtual繼承Base
{
protected:
	int k;
};

class Derived3: public Derived1, public Derived2
{
protected:
	int sum;
public:
	Derived3(int n1, int n2, int n3)
	{
		i = n1;	//令Base::i = n1
		j = n2;	//令Derived1::j = n2
		k = n3;	//令Derived2::k = n3
		sum = i + j + k;	//令sum=i+j+k
	}
	void show()
	{
		cout << "i = " << i << endl;	//輸出Base::i
		cout << "j = " << j << endl;	//輸出Derived1::j
		cout << "k = " << k << endl;	//輸出Derived2::k
		cout << "sum = " << sum << endl;	//輸出Derived3::sum
	}
};

int main(int argc, char** argv)
{
	Derived3 d3(10, 20, 30); 	//建立Derived3物件d3
	d3.show();	//呼叫Derived3::show
	return 0;
}
