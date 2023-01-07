// �x�s�ɦW�Gd:\C++14\C1409.cpp
#include <iostream>
#include <cmath>
using namespace std;

#define PI 3.1415925f

class Line	//�w�q��H���O
{
private:
	double length;
public:
	Line(double length) { 	//�ŧiLine�إߪ�
		this->length = length; 	//�ܼ�length=�Ѽ�length
	}
	double getLength() {  	//�ŧi���olength��k
		return this->length;	//�Ǧ^�ܼ�length��
	}
	virtual double getArea() = 0;	//�ŧi�s�������
};

class Square: public Line
{
public:
	Square(double length): Line(length) {  	//�ŧiSquare�إߪ�
	}
	double getArea() {  	//�W��getArea()��k
		return pow(getLength(), 2); 	//�Ǧ^����έ��n
	}
};

class Circle: public Line
{
public:
	Circle(int radius): Line(radius) {  	//�ŧiCircle�إߪ�
	}
	double getArea() {  	//�W��getArea()��k
		return PI * pow(getLength(), 2); 	//�Ǧ^��έ��n
	}
};

int main(int argc, char** argv)
{
	Square squ(5);	//�إ�Square����squ
	Circle cir(10);	//�إ�Circle����cir
	cout << "�������� = " << squ.getLength();	//�I�sSquare����k
	cout << "\t����έ��n = " << squ.getArea();	//�I�sSquare����k
	cout << "\n��Υb�| = " << cir.getLength();	//�I�sSquare����k
	cout << "\t��έ��n = " << cir.getArea();	//�I�sCircle����k
	cout << endl;
	return 0;
}
