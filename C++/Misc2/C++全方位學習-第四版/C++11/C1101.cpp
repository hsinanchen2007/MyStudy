//�ɮצW�١Gd:\C++11\C1101.cpp
#include <iostream>
#include <cmath>
using namespace std;

#define PI 3.141593

struct Cuboid	//�ŧiCuboid���c
{
	int length;	//Cuboid����Ʀ���1
	int width;	//Cuboid����Ʀ���2
	int height;	//Cuboid����Ʀ���3
};

int area(Cuboid r)	//�p���������n���
{
	return 2 * (r.length * r.width 
		+ r.width * r.height 
		+ r.height * r.length);
}

int volumn(Cuboid r)	//�p���������n���
{
	return r.length * r.width * r.height;
}

int main(int argc, char** argv)
{
	Cuboid rt = {6, 8, 10};	//�إ�Cuboid���c�ܼ�
	cout << "������G\n";
	cout << "�� = " << rt.length << endl;	//��X�����骺��
	cout << "�e = " << rt.width << endl;	//��X�����骺�e
	cout << "�� = " << rt.height << endl;	//��X�����骺��
	cout << "���n = " << area(rt) << "���褽��\n";	//��X��������n
	cout << "��n = " << volumn(rt) << "�ߤ褽��\n";	//��X��������n
	return 0;
}
