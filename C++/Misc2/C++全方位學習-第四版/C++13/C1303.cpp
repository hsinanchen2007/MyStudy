//�ɮצW�١Gd:\C++13\C1303.cpp
#include <iostream>
using namespace std;

class TwoD		//�w�qTwoD���O
{
protected:
	int x, y;
public:
	void setxy(int n, int m) {
		x = n; y = m;
	}
	void showxy() {
		cout << "�����y�� : p(" << x << ", " 
			<< y << ") " << endl;
	}
};

class ThreeD: public TwoD	//�Hpublic�~��TwoD
{
protected:
	int z;
public:
	void setz(int o) {
		z = o;
	}
	void showxyz() {
		cout << "�Ŷ��y�� : s(" << x << ", " << y 
			<< ", " << z << ") " << endl;
	}
};

class Cube: public ThreeD	//�Hpublic�~��ThreeD
{					//�����~��TwoD���O
public:
	void showarea() {
		cout << "���n = " << x * y << endl;	//�����s��x, y��
	}
	void showcube() {
		cout << "��n = " << x * y * z	//�����s��x y,�����s��z
			<< endl;
	}
};

int main(int argc, char** argv)
{
	Cube p;		//�إ�Cube���O����
	p.setxy(2,5);	//�����I�s��¦���O����
	p.showxy();	//�����I�s��¦���O����
	p.showarea();	//�����I�s�l�����O2����
	cout << endl;
	p.setz(8);	//�����I�s�l�����O1����
	p.showxyz();	//�����I�s�l�����O1����
	p.showcube();	//�����I�s�l�����O2����
	return 0;
}
