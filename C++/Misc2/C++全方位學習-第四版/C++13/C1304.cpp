//�ɮצW�١Gd:\C++13\C1304.cpp
#include <iostream>
using namespace std;

class PointXY	//�ŧi��¦���O1,PointXY
{
protected:
	int x, y;
public:
	void setxy(int n, int m) {
		x = n; y = m;
	}
};

class PointZ	//�ŧi��¦���O2,PointZ
{
protected:
	int z;
public:
	void setz(int o) {
		z = o;
	}
};

class Cube: public PointXY, public PointZ	//�Hpublic�~��PointXY
{					//�Hpublic�~��PointZ
public:
	void showxy() {
		cout << "�����y�� : p(" << x << ", " 	//�s��x, y��
			 << y << ") " << endl;
	}
	void showxyz() {
		cout << "�Ŷ��y�� : s(" << x << ", " << y	//�s��x, y, z
			 << ", " << z << ") " << endl;
	}
	void showarea() {
		cout << "���n = " << x * y << endl;	//�s��x, y��
	}
	void showcube() {
		cout << "��n = " << x * y * z << endl;	//�s��x, y, z
	}
};

int main(int argc, char** argv)
{
	Cube p;		//�إ߭l�����OCube����
	p.setxy(2,5);	//�����I�s��¦���O1����
	p.showxy();	//�����I�s�l�����O����
	p.showarea();	//�����I�s�l�����O����
	cout << endl;
	p.setz(8);	//�����I�s��¦���O2����
	p.showxyz();	//�����I�s�l�����O����
	p.showcube();	//�����I�s�l�����O����
	return 0;
}
