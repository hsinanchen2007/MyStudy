//檔案名稱：d:\C++11\C1112.cpp
#include <iostream>
using namespace std;

class Calculate	//定義Calculate類別
{
	int x;
public:
	Calculate(int);	//建立者函數原型
	void sum(Calculate);	//加法運算函數原型
	void display();	//顯示x值函數原型
};

Calculate::Calculate(int n)	//定義建立者函數
{
	x = n;
}

void Calculate::sum(Calculate obj)	//定義加法運算函數
{
	x += obj.x;
}

void Calculate::display()	//定義顯示 x 值函數
{
	cout << x;
}

int main(int argc, char** argv)
{
	Calculate a(100), b(200);	//定義 a.x=100,b.x=200
	a.display();	//顯示 a.x=100 值
	cout << '+';	//顯示 + 號
	b.display();	//顯示 b.x=200 值
	cout << '=';	//顯示 = 號
	a.sum(b);	//計算 a.x = a.x + b.x
	a.display();	//顯示計算後 a.x=300 值
	cout << endl;	//跳行
	return 0;
}
