//�ɮצW�١Gd:\C++15\C1509.cpp
#include <iostream>
#include <fstream>
using namespace std;

class Student	//�w�qStudent���O
{
protected:
	int student_id;
	char student_name[40];
public:
	void showdata()	//��ܸ�ƨ��
	{
		cout << student_id << '\t' << student_name << endl;
	}
};

int main(int argc, char** argv)
{
	Student stuData;
	ifstream filePtr;
	int n;

	filePtr.open("d:\\C++15\\C1505.dat", ios::binary|ios::in);	//�}�ҿ�J��
	if(!filePtr) {	//�Y�}���ɮ׿��~
		cout << "�}�ҿ�J�ɿ��~�I\n";
		system("PAUSE");
		exit(1);	//�D���`�����{��
	} else {			//�_�h
		cout << "�п�J�nŪ���ĴX����ơG";
		cin >> n;
		int pos = (n-1) * sizeof(stuData);	//�p���Ʀ�m
		filePtr.seekg(pos, ios::beg);	//����get����
		filePtr.read((char*) &stuData, sizeof(stuData));	//Ū�����
		stuData.showdata();	//�I�s��ܸ�ƨ��
	}
	filePtr.close();
	return 0;
}
