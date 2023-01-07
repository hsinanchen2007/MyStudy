//�ɮצW�١Gd:\C++13\C1310.cpp
#include <iostream>
using namespace std;

class Point		//�w�qPoint���O
{
	int x, y;
public:
	Point(int = 0, int = 0);	//�ŧiPoint�إߪ�
	void setPoint(int, int); 
	int getx() const { return x; }
	int gety() const { return y; }
};

class Square	//�w�qSquare���O
{
	int area() const;
public:
	Point comP;	//�]�tPoint����
	Square(int x = 0, int y = 0);	//�ŧiSquare�إߪ�
	int getarea() const { return area(); }
};

Point::Point(int a, int b)	//�w�qPoint�إߪ�
{
	setPoint(a, b);
}

void Point::setPoint(int a, int b)	//�w�qsetPoint���
{
	x = a; y = b;
}

Square::Square(int a, int b)	//�w�qSquare�إߪ�
{
	comP.setPoint(a, b);
}

int Square::area() const	//�w�qarea���
{
	return comP.getx() * comP.gety();
}

int main(int argc, char** argv)
{
	Point p(72, 115);	//�w�qPoint����p
	Square s(37, 43);	//�w�qSquare����s
	cout << "�I�y�СGp(" << p.getx() << ", " 
		<< p.gety() << ')' << endl;	//����Ip�y��
	cout << "�x�ήy�СGs(" << s.comP.getx() << ", " 
		<< s.comP.gety() << ')' << endl;	//��ܯx��s���I�y��
	cout << "�x�έ��n�G" << s.comP.getx() << " * " 
		<< s.comP.gety() << " = " << s.getarea()
		<< endl;	//��ܯx��s���n
	return 0;
}
