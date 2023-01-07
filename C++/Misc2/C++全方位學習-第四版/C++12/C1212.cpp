//�ɮצW�١Gd:\C++12\C1212.cpp
#include <iostream>
#include <cmath>
using namespace std;

class Polar		//�ŧi Polar ���O
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

class Cartesian	//�ŧi Cartesian ���O
{
	double x;
	double y;
public:
	Cartesian() {x = y = 0.0;}
	Cartesian(double a, double b) {x = a; y = b;}
	Cartesian operator = (Polar p);	//�ŧi�h�� = �����
	friend ostream & operator << (ostream& out, Cartesian& obj);
};

Cartesian Cartesian::operator = (Polar p)	//�w�q�h�� = �����
{
	double r = p.getr();
	double a = p.geta();
	x = r * cos(a);
	y = r * sin(a);
	return Cartesian(x, y);
}

ostream & operator << (ostream& out, Cartesian& obj) 
{					//�h��Cartesian<<�Ÿ�
	out << "c(" << obj.x << ", " << obj.y << ")";
	return out;
}

ostream & operator << (ostream& out, Polar& obj)
{					//�h��Polar << �B��Ÿ�
	out << "p(" << obj.radius << ", " << obj.angle << ")";
	return out;
}

int main(int argc, char** argv)
{
	Polar p(2.0, 35.0); 	//�إ߷��y��p�I��m
	Cartesian c; 	//�إߥ����y��c
	c = p; 		//�I�s�h�� = �����
	cout << "���y�СG" << p << endl
		 << "�ন�����y�СG" << c << endl;
	return 0;
}
