//檔案名稱：d:\C++12\C1212.cpp
#include <iostream>
#include <cmath>
using namespace std;

class Polar		//宣告 Polar 類別
{
private:
	double radius;
	double angle;
public:
	Polar() {radius = angle = 0.0;}
	Polar(double r, double a) {radius = r; angle = a;}
	double getr() {return radius;}
	double geta() {return angle;}
	friend ostream & operator << (ostream& out, Polar& obj);
};

class Cartesian	//宣告 Cartesian 類別
{
	double x;
	double y;
public:
	Cartesian() {x = y = 0.0;}
	Cartesian(double a, double b) {x = a; y = b;}
	Cartesian operator = (Polar p);	//宣告多載 = 號函數
	friend ostream & operator << (ostream& out, Cartesian& obj);
};

Cartesian Cartesian::operator = (Polar p)	//定義多載 = 號函數
{
	double r = p.getr();
	double a = p.geta();
	x = r * cos(a);
	y = r * sin(a);
	return Cartesian(x, y);
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
	c = p; 		//呼叫多載 = 號函數
	cout << "極座標：" << p << endl
		 << "轉成平面座標：" << c << endl;
	return 0;
}
