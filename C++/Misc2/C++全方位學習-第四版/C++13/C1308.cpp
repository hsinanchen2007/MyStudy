//�ɮצW�١Gd:\C++13\C1308.cpp
#include <iostream>
using namespace std;

class Point		//�w�qPoint���O
{
protected:
	int x, y;
public:
	Point (int n, int m) {	//Point �إߪ�
		x = n; y = m; 
	}
	void showpoint() {
		cout << "p(" << x << ", " << y << ')'
			 << endl; 
	}
};

class Area: public Point	//�w�qArea�~��Point
{
public:
	Area (int x, int y) : Point (x, y) {	//Area�إߪ�
	}				//�öǻ�x,y�Ѽƨ�Point
	void showarea() { 
		cout << "length = " << x
			<< "\twidth = " << y
			<< "\tarea = " << x * y << endl;
	}
};

int main(int argc, char** argv)
{
	Point p(3, 4);	//x=3, y=4
	Area a(5, 6);	//x=5, y=6
	cout << "�Q�ΰ�¦���O��������I�G";
	p.showpoint();	//��� p(3, 4)
	cout << "�Q�έl�����O������ܭ��n�G";
	a.showarea();	//��� area = 12
	return 0;
}
