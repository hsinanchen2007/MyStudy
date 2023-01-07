//�ɮצW�١Gd:\C++11\C1103.cpp
#include <iostream>
#include <cmath>
using namespace std;

#define PI 3.141593f

class Cuboid	//�ŧi���������O
{
public:
	int length;	//Cuboid����Ʀ���1
	int width;	//Cuboid����Ʀ���2
	int height;	//Cuboid����Ʀ���3
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
public:
	float radius;	//Cylinder����Ʀ���1
	float height;	//Cylinder����Ʀ���2
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
	Cuboid rt = {6, 8, 10};	//�إ�Cuboid���c���
	cout << "������G\n";
	cout << "�� = " << rt.length << endl;	//��X�����骺��
	cout << "�e = " << rt.width << endl;	//��X�����骺�e
	cout << "�� = " << rt.height << endl;	//��X�����骺��
	cout << "���n = " << rt.area() << "���褽��\n";	//��X��������n
	cout << "��n = " << rt.volumn() << "�ߤ褽��\n\n";	//��X��������n

	Cylinder cl = {5.0, 10.0};	//�إ�Cylinder���c���
	cout << "��W��G\n";
	cout << "�b�| = " << cl.radius << endl;	//��X��W��b�|
	cout << "�� = " << cl.height << endl;	//��X�����骺��
	cout << "���n = " << cl.area() << "���褽��\n";	//��X��W����n
	cout << "��n = " << cl.volumn() << "�ߤ褽��\n";	//��X��W����n
	return 0;
}
