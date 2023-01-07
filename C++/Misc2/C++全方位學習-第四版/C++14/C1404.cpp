//檔案名稱：d:\C++14\C1404.cpp
#include <iostream>
#include <cmath>
using namespace std;

#define PI 3.1415926f

class InchArea	//宣告基礎類別
{
protected:
	double inch;
public:
	InchArea(double in) {	//基礎類別建立者
		inch = in;
	}
	virtual double getLength() {	//虛擬getLength函數
		return inch;
	}
	double getArea() {
		return int(pow(getLength(), 2));
	}
};

class FeetArea: public InchArea	//宣告衍生類別
{
protected:
	double feet;
public:
	FeetArea(double ft): InchArea(ft*12) {	//基礎類別建立者
		feet = ft;
	}
	virtual double getLength() {	//虛擬多載getLength
		return feet;
	}
};

int main(int argc, char** argv)
{
	InchArea ia(5);	//建立基礎類別物件ia
	cout << "正方形長 5 英吋, 面積 = " << ia.getArea() 
		<< " 平方英吋" << endl;	//呼叫基礎類別方法

	FeetArea fa(8);	//建立衍生類別物件fa
	cout << "正方形長 8 英呎, 面積 = " << fa.getArea() 
		<< " 平方英呎" << endl;	//呼叫基礎類別方法
	return 0;
}
