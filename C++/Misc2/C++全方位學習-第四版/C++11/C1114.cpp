//檔案名稱：d:\C++11\C1114.cpp
#include <iostream>
using namespace std;

class Calculate	//宣告Calculate類別
{
	int x;		//私用資料成員x
public:
	Calculate(int n);	//建立者函數原型
	Calculate *calcSum(Calculate obj);	//加法運算函數原型
	void showSum(Calculate a, Calculate b);	//輸出物件函數原型
};

Calculate::Calculate(int n) {	//建立者函數
	x = n;
};

Calculate *Calculate::calcSum(Calculate obj) {	//加法運算,傳遞物件參數
	x += obj.x;	//x = x + obj.x
	return this;	//傳回this->x
};

void Calculate::showSum(Calculate a, Calculate b) {	//輸出物件函數
	cout << "a = " << a.x << endl;	//輸出a.x值
	cout << "b = " << b.x << endl;	//輸出b.x值
	cout << "a + b = " << this->x << endl;	//輸出c.x值
};

int main(int argc, char** argv)
{
	Calculate a(100), b(200), c(0);	//定義a.x=100, b.x=200
	c = *(a.calcSum(b));	//計算c.x = a.x + b.x
	c.showSum(a, b);	//輸出a, b, c物件值
	return 0;
}
