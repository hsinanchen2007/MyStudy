//�ɮצW�١Gd:\C++13\C1309.cpp
#include <iostream>
using namespace std;

class TwoD		//�w�qTwoD���O
{
protected:
	int x, y;
public:
	TwoD(int m, int n) {
		x = m; y = n;
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
	ThreeD(int m, int n, int o): TwoD(m, n)	{ //�ǻ�m, n�Ѽƨ�TwoD
		z = o;
	}
	void showxyz() {
		cout << "�Ŷ��y�� : s(" << x << ", " << y 
			 << ", " << z << ") " << endl;
	}
};

int main(int argc, char** argv)
{
	TwoD p(3, 4);	//�إ�TwoD����
	ThreeD s(3, 4, 5);	//�إ�ThreeD����
	p.showxy();	//�����I�sTwoD����
	s.showxyz();	//�����I�sThreeD����
	return 0;
}
