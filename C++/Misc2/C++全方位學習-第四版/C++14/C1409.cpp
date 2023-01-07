// 儲存檔名：d:\C++14\C1409.cpp
#include <iostream>
#include <cmath>
using namespace std;

#define PI 3.1415925f

class Line	//定義抽象類別
{
private:
	double length;
public:
	Line(double length) { 	//宣告Line建立者
		this->length = length; 	//變數length=參數length
	}
	double getLength() {  	//宣告取得length方法
		return this->length;	//傳回變數length值
	}
	virtual double getArea() = 0;	//宣告存虛擬函數
};

class Square: public Line
{
public:
	Square(double length): Line(length) {  	//宣告Square建立者
	}
	double getArea() {  	//超載getArea()方法
		return pow(getLength(), 2); 	//傳回正方形面積
	}
};

class Circle: public Line
{
public:
	Circle(int radius): Line(radius) {  	//宣告Circle建立者
	}
	double getArea() {  	//超載getArea()方法
		return PI * pow(getLength(), 2); 	//傳回圓形面積
	}
};

int main(int argc, char** argv)
{
	Square squ(5);	//建立Square物件squ
	Circle cir(10);	//建立Circle物件cir
	cout << "正方形邊長 = " << squ.getLength();	//呼叫Square的方法
	cout << "\t正方形面積 = " << squ.getArea();	//呼叫Square的方法
	cout << "\n圓形半徑 = " << cir.getLength();	//呼叫Square的方法
	cout << "\t圓形面積 = " << cir.getArea();	//呼叫Circle的方法
	cout << endl;
	return 0;
}
