//�ɮצW�١Gd:\C++11\C1114.cpp
#include <iostream>
using namespace std;

class Calculate	//�ŧiCalculate���O
{
	int x;		//�p�θ�Ʀ���x
public:
	Calculate(int n);	//�إߪ̨�ƭ쫬
	Calculate *calcSum(Calculate obj);	//�[�k�B���ƭ쫬
	void showSum(Calculate a, Calculate b);	//��X�����ƭ쫬
};

Calculate::Calculate(int n) {	//�إߪ̨��
	x = n;
};

Calculate *Calculate::calcSum(Calculate obj) {	//�[�k�B��,�ǻ�����Ѽ�
	x += obj.x;	//x = x + obj.x
	return this;	//�Ǧ^this->x
};

void Calculate::showSum(Calculate a, Calculate b) {	//��X������
	cout << "a = " << a.x << endl;	//��Xa.x��
	cout << "b = " << b.x << endl;	//��Xb.x��
	cout << "a + b = " << this->x << endl;	//��Xc.x��
};

int main(int argc, char** argv)
{
	Calculate a(100), b(200), c(0);	//�w�qa.x=100, b.x=200
	c = *(a.calcSum(b));	//�p��c.x = a.x + b.x
	c.showSum(a, b);	//��Xa, b, c�����
	return 0;
}
