//�ɮצW�١Gd:\C++15\C1511.cpp
#include <iostream>
#include <fstream>
using namespace std;

struct Student
{
	int student_id;
	char student_name[40];
};

int main(int argc, char** argv)
{
	Student stuData;
	ifstream filePtr;

	filePtr.open("d:\\C++15\\C1505.dat", ios::binary|ios::in);	//�}�ҿ�J��
	if(!filePtr) {
		cout << "�}�ҿ�J�ɿ��~�I\n";
		exit(1);	//�D���`�����{��
	} else {
		filePtr.seekg(0, ios::end);	//���ʫ��Ш��ɧ�
		int endpos = filePtr.tellg();	//���o�ɮצ줸�ռ�
		int n = endpos / sizeof(stuData);	//���H�w�ľ��j�p
		cout << "d:\\C++15\\C1505.dat �@�� " << n << " �����";	//��ܸ�Ƶ���
	}
	filePtr.close();
	cout << endl;
	return 0;
}
