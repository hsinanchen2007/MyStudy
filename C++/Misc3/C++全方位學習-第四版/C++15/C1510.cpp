//�ɮצW�١Gd:\C++15\C1510.cpp
#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char** argv)
{
	ifstream filePtr;

	filePtr.open("d:\\C++15\\C1505.dat", ios::binary|ios::in);	//�}�ҿ�J�ɮ�
	if(!filePtr) {	//�Y�}���ɮ׿��~
		cout << "�}�ҿ�J�ɿ��~�I\n";
		system("PAUSE");
		exit(1);	//�D���`�����{��
	} else {		//�_�h
		filePtr.seekg(0, ios::end);	//���ʫ��Ш��ɧ�
		int endpos = filePtr.tellg();	//���o���Ц�m
		cout << "d:\\C++15\\C1505.dat ���j�p = "
			<< endpos << " bytes" << endl;	//����ɮפj�p
	}
	filePtr.close();
	return 0;
}
