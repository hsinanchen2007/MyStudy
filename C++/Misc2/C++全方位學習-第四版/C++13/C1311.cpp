//�ɮצW�١Gd:\C++13\C1311.cpp
#include <iostream>
using namespace std;

class TwoD	//�w�qTwoD���O
{
protected:
	int x, y;
public:
	TwoD() {}	//TwoD���t�Ѽƫإߪ�
	TwoD(int m, int n) { x = m; y = n; }	//TwoD�t�Ѽƫإߪ�
	void setx(int m) { x = m; }	//�]�wx��public���
	void sety(int n) { y = n; }	//�]�wy��public���
	int getx() { return x; }	//���ox��public���
	int gety() { return y; }	//���oy��public���
	void showxy() {
		cout << "�����y�� : p(" << x << ", " 
			<< y << ") " << endl;
	}
};

class ThreeD	//�w�qThreeD���O
{
protected:
	int z;
public:
	TwoD d;		//�]�tTwoD���O
	ThreeD(int m, int n, int o) {	//ThreeD �t�Ѽƫإߪ�
		d.setx(m); 	//�z�Ld.setx()�]�wx��
		d.sety(n);	//�z�Ld.sety()�]�wy��
		z = o;
	}
	void showxyz() {
		cout << "�Ŷ��y�� : s(" 
			 << d.getx() << ", " 	//�z�Ld.getx()���ox
			 << d.gety() << ", " 	//�z�Ld.gety()���oy
			 << z << ") " << endl;
	}
};

int main(int argc, char** argv)
{
	TwoD p(3, 4);	//�إ�TwoD���O����p
	ThreeD s(3, 4, 5);	//�إ�ThreeD���O����s
	p.showxy();	//�����I�sTwoD����
	s.showxyz();	//�����I�sThreeD����
	return 0;
}
