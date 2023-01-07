//檔案名稱：d:\C++11\C1110.cpp
#include <iostream>
using namespace std;

class First
{
	int x;
public:
	void setx(int var) {
		x = var;
	}
	friend int getx(First obj) {	//定義 friend 函數
		return obj.x;
	}
};

class Second
{
	int y;
public:
	void sety(int var) {
		y = var;
	}
	void showxy(First obj) {
		cout << "x = " << getx(obj) << endl;	//呼叫 friend 函數
		cout << "y = " << y << endl;
	}
};

int main(int argc, char** argv)
{
	First A;
	Second B;
	A.setx(10);
	B.sety(20);
	B.showxy(A);
	return 0;
}
