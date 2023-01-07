//�ɮצW�١Gd:\C++12\C1211.cpp
#include <iostream>
#include <cmath>
using namespace std;

class Cartesian	//�ŧi Cartesian ���O
{
private:
	double x;
	double y;
public:
	Cartesian () {x = y = 0.0;}
	Cartesian (double a, double b) {x = a; y = b;}
	friend ostream & operator << (ostream& out, Cartesian& obj);
};

class Polar		//�ŧi Polar ���O
{
	double radius;
	double angle;
public:
	Polar() {radius = angle = 0.0;}
	Polar(double r, double a) {radius = r; angle = a;}
	operator Cartesian();	//�ŧi���A�ഫ���
	friend ostream & operator << (ostream& out, Polar& obj);
};

Polar::operator Cartesian()	//�ŧi���A�ഫ���
{					//Polar �ন Cartesian 
	double xx, yy;
	xx = radius * cos(angle);
	yy = radius * sin(angle);
	return Cartesian(xx, yy);
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
	c = p;		//�I�sCartesian���
	cout << "���y�СG" << p << endl
		 << "�ন�����y�СG" << c << endl;
	return 0;
}
