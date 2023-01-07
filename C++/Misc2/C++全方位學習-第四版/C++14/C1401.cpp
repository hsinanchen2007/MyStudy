//檔案名稱：d:\C++14\C1401.cpp
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
	void show(char str1[], char str2[]) {	//基礎類別方法
		cout << str1 << a << endl;
		cout << str2 << b << endl;
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
	void show(char str3[]) {	//衍生類別多載方法
		cout << str3 << c << endl;
	}
};

int main(int argc, char** argv)
{
	Derived d(2, 3, 5);	//建立Derived物件d
	char s1[] = "a = ";	//定義並起始s1字串
	char s2[] = "b = ";	//定義並起始s2字串
	char s3[] = "c = ";	//定義並起始s3字串
	d.Base::show(s1, s2);	//呼叫Base方法
	d.Derived::show(s3);	//呼叫Derived多載方法
	return 0;
}
