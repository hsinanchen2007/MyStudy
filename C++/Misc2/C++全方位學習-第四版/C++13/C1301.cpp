//�ɮצW�١Gd:\C++13\C1301.cpp
#include <iostream>
using namespace std;

class Point	//�w�qPoint���O
{
protected:
	int x, y;
public:
	void set(int n, int m) {
		x = n; y = m;
	}
	void show() {
		cout << "��m = p(" << x << ", " << y << ") " << endl;
	}
};

class Area: public Point	//�Hpublic�~��Point
{
public:
	void showarea() {
		cout << "���n = " << x * y << endl;
	}
};

int main(int argc, char** argv)
{
	Area p;		//�إ߭l�����O����
	p.set(2,5);	//�����I�s��¦���O����
	p.show();	//�����I�s��¦���O����
	p.showarea();	//�I�s�l�����O�������
	return 0;
}
