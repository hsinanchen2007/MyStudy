//檔案名稱：d:\C++12\C1211.cpp
#include <iostream>
#include <cmath>
using namespace std;

class Cartesian	//宣告 Cartesian 類別
{
private:
	double x;
	double y;
public:
	Cartesian () {x = y = 0.0;}
	Cartesian (double a, double b) {x = a; y = b;}
	friend ostream & operator << (ostream& out, Cartesian& obj);
};

class Polar		//宣告 Polar 類別
{
	double radius;
	double angle;
public:
	Polar() {radius = angle = 0.0;}
	Polar(double r, double a) {radius = r; angle = a;}
	operator Cartesian();	//宣告型態轉換函數
	friend ostream & operator << (ostream& out, Polar& obj);
};

Polar::operator Cartesian()	//宣告型態轉換函數
{					//Polar 轉成 Cartesian 
	double xx, yy;
	xx = radius * cos(angle);
	yy = radius * sin(angle);
	return Cartesian(xx, yy);
}

ostream & operator << (ostream& out, Cartesian& obj)
{					//多載Cartesian<<符號
	out << "c(" << obj.x << ", " << obj.y << ")";
	return out;
}

ostream & operator << (ostream& out, Polar& obj)
{					//多載Polar << 運算符號
	out << "p(" << obj.radius << ", " << obj.angle << ")";
	return out;
}

int main(int argc, char** argv)
{
	Polar p(2.0, 35.0); 	//建立極座標p點位置
	Cartesian c; 	//建立平面座標c
	c = p;		//呼叫Cartesian函數
	cout << "極座標：" << p << endl
		 << "轉成平面座標：" << c << endl;
	return 0;
}
