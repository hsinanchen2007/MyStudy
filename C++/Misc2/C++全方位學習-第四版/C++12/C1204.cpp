//�ɮצW�١Gd:\C++12\C1204.cpp
#include <iostream>
using namespace std;

class Cuboid	//�ŧi���������O
{
private:
	int length;	//Cuboid����Ʀ���1
	int width;	//Cuboid����Ʀ���2
	int height;	//Cuboid����Ʀ���3
public:
	Cuboid(int l, int w)	//���������إߪ�
	{
		length = l;
		width = w;
		height = 0;
	}
	Cuboid(int l, int w, int h)	//����������إߪ�
	{
		length = l;
		width = w;
		height = h;
	}
	int area()	//�p�⭱�n�Ϊ��n���
	{
		if (height == 0)
			return length * width;
		else
			return 2*(length*width+width*height+height*length);

	}
};

int main(int argc, char** argv)
{
	Cuboid rt(6, 8);	//�إߨð_�lrt������
	Cuboid cb(6, 8, 10);	//�إߨð_�lcb������

	cout << "����έ��n = " << rt.area();	//��X����έ��n
	cout << "���褽��\n";
	cout << "��������n = " << cb.area();	//��X��������n
	cout << "���褽��\n";
	return 0;
}
