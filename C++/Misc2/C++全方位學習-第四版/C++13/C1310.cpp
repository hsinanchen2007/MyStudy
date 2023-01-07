//檔案名稱：d:\C++13\C1310.cpp
#include <iostream>
using namespace std;

class Point		//定義Point類別
{
	int x, y;
public:
	Point(int = 0, int = 0);	//宣告Point建立者
	void setPoint(int, int); 
	int getx() const { return x; }
	int gety() const { return y; }
};

class Square	//定義Square類別
{
	int area() const;
public:
	Point comP;	//包含Point物件
	Square(int x = 0, int y = 0);	//宣告Square建立者
	int getarea() const { return area(); }
};

Point::Point(int a, int b)	//定義Point建立者
{
	setPoint(a, b);
}

void Point::setPoint(int a, int b)	//定義setPoint函數
{
	x = a; y = b;
}

Square::Square(int a, int b)	//定義Square建立者
{
	comP.setPoint(a, b);
}

int Square::area() const	//定義area函數
{
	return comP.getx() * comP.gety();
}

int main(int argc, char** argv)
{
	Point p(72, 115);	//定義Point物件p
	Square s(37, 43);	//定義Square物件s
	cout << "點座標：p(" << p.getx() << ", " 
		<< p.gety() << ')' << endl;	//顯示點p座標
	cout << "矩形座標：s(" << s.comP.getx() << ", " 
		<< s.comP.gety() << ')' << endl;	//顯示矩形s頂點座標
	cout << "矩形面積：" << s.comP.getx() << " * " 
		<< s.comP.gety() << " = " << s.getarea()
		<< endl;	//顯示矩形s面積
	return 0;
}
