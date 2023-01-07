//�ɮצW�١Gd:\C++11\C1104.cpp
#include <iostream>
#include <cmath>
using namespace std;

#define PI 3.141593f

class Cuboid	//�ŧi���������O
{
private:
	int length;	//Cuboid����Ʀ���1
	int width;	//Cuboid����Ʀ���2
	int height;	//Cuboid����Ʀ���3
public:
	void setCuboid(int l, int w, int h)	//�]�wCuboid��Ʀ���
	{
		length = l;
		width = w;
		height = h;
	}
	int getLength()	//���olength��ƨ��
	{
		return length;
	}
	int getWidth()	//���owidth��ƨ��
	{
		return width;
	}
	int getHeight()	//���oheight��ƨ��
	{
		return height;
	}
	int area()	//�p���������n���
	{
		return 2 * (length * width 
			+ width * height 
			+ height * length);
	}
	int volumn()	//�p���������n���
	{
		return length * width * height;
	}
};

class Cylinder	//�ŧi��W�����O
{
	float radius;	//Cylinder����Ʀ���1
	float height;	//Cylinder����Ʀ���2
public:
	void setCylinder(float r, float h)	//�]�wCylinder��Ʀ���
	{
		radius = r;
		height = h;
	}
	float getRadius()	//���oradius��ƨ��
	{
		return radius;
	}
	float getHeight()	//���oheight��ƨ��
	{
		return height;
	}
	float area()	//�p���W����n���
	{
		return 2 * PI * radius * height;
	}
	float volumn()	//�p���W����n���
	{
		return PI * float(pow(radius, 2)) * height;
	}
};

int main(int argc, char** argv)
{
	Cuboid rt;	//�إ�Cuboid����
	rt.setCuboid(6, 8, 10);	//�_�lrt������
	cout << "������G\n";
	cout << "�� = " << rt.getLength() << endl;	//��X�����骺��
	cout << "�e = " << rt.getWidth() << endl;	//��X�����骺�e
	cout << "�� = " << rt.getHeight() << endl;	//��X�����骺��
	cout << "���n = " << rt.area() << "���褽��\n";	//��X��������n
	cout << "��n = " << rt.volumn() << "�ߤ褽��\n\n";	//��X��������n

	Cylinder cl;	//�إ�Cylinder����
	cl.setCylinder(5.0, 10.0);	//�_�lcl������
	cout << "��W��G\n";
	cout << "�b�| = " << cl.getRadius() << endl;	//��X��W��b�|
	cout << "�� = " << cl.getHeight() << endl;	//��X�����骺��
	cout << "���n = " << cl.area() << "���褽��\n";	//��X��W����n
	cout << "��n = " << cl.volumn() << "�ߤ褽��\n";	//��X��W����n
	return 0;
}
