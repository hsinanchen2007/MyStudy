//�ɮצW�١Gd:\C++15\C1501.cpp
#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char** argv)
{
	ofstream filePtr;	//�إ��ɮת���(�N��)
	filePtr.open("d:\\C++15\\C1501.txt", ios::out);	//�}�ҿ�X��C1501.txt
	if(!filePtr.is_open()) {	//�Y�}���ɮץN�����~
		cout << "�}���ɮ׿��~�I\n";
		system("PAUSE");
		exit(1);	//�D���`�����{��
	} else {		//�_�h
		filePtr << "Life is not easy, but in the long run \n";
		filePtr << "it's easier than going to elaborate ends \n";
		filePtr << "to deny it.\n";	//�g�J�r����ɮ�
	}
	filePtr.close();	//�����ɮת���(�N��)
	return 0;
}
