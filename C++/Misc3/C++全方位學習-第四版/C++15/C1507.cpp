//�ɮצW�١Gd:\C++15\C1507.cpp
#include <iostream>
#include <fstream>
using namespace std;

class Student	//�w�q Student ���O
{
protected:		//�O�@��
	int student_id;
	char student_name[40];
public:			//���ΰ�
	void showdata()	//��ܸ�ƨ��
	{
		cout << student_id << '\t' << student_name << endl;
	}
};

int main(int argc, char** argv)
{
	Student stuData;	//�إ����O����
	ifstream filePtr;	//�إ߿�J�ɮת���
	filePtr.open("d:\\C++15\\C1505.dat", ios::in);	//�}�ҿ�J��
	if(!filePtr) {	//�Y�ɮץN�����~
		cout << "�}�ҿ�J�ɿ��~�I\n";
		system("PAUSE");
		exit(1);	//�D���`�����{��
	} else {		//�h
		filePtr.read((char*) &stuData,	//Ū����ƨ�w�İ�
			sizeof(stuData));	//Ū������=�w�İϤj�p
		while(!filePtr.eof()) {	//Ū����ưj��
				stuData.showdata();	//�I�s��ܸ�ƨ��
				filePtr.read((char*) &stuData,	//Ū����ƨ�w�İ�
				    sizeof(stuData));	//Ū������=�w�İϤj�p
		}
	}
	filePtr.close();
	return 0;
}
