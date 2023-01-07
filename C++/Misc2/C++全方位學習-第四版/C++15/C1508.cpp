//�ɮצW�١Gd:\C++15\C1508.cpp
#include <iostream>
#include <fstream>
using namespace std;

const char filename[] = "d:\\C++15\\C1508.dat";

class Student	//�w�qStudent���O
{
protected:
	int student_id;
	char student_name[40];
public:
	int getId();	//�ŧigetId��ƭ쫬
	void setData();	//�ŧisetData��ƭ쫬
	void showData();	//�ŧishowData��ƭ쫬
	void write();	//�ŧiwrite��ƭ쫬
	void append();	//�ŧiappend��ƭ쫬
	void read();	//�ŧiread��ƭ쫬
};

int Student::getId()	//�w�qgetId���
{
	return student_id;
}

void Student::setData()	//�w�qsetData���
{
	cout << "�п�J�Ǹ��P�m�W (��J 0 0 �h����)�G";
	cin >> student_id >> student_name;
}

void Student::showData()	//�w�qshowData���
{
	cout << student_id << '\t' << student_name << endl;
}

void Student::write()	//�w�qwrite���
{
	ofstream filePtr;
	filePtr.open(filename, ios::binary | ios::out);
	if(!filePtr) {
		cout << "�}�ҿ�X�ɿ��~�I\n";
		system("PAUSE");
		exit(1);	//�D���`�����{��
	} else {
		while(1) {
			setData();
			if(getId() != 0)
				filePtr.write((char*) this, sizeof(*this));
			else
				break;
		}
	}
	filePtr.close();
}

void Student::append()	//�w�qappend���
{
	ofstream filePtr;
	filePtr.open(filename, ios::binary | ios::app);
	if(!filePtr) {
		cout << "�}�Ҫ��[�ɿ��~�I\n";
		system("PAUSE");
		exit(1);	//�D���`�����{��
	} else {
		while(1) {
			setData();
			if(getId() != 0)
				filePtr.write((char*) this, sizeof(*this));
			else
				break;
		}
	}
	filePtr.close();
}

void Student::read()	//�w�qread���
{
	ifstream filePtr;
	filePtr.open(filename, ios::binary | ios::in);
	if(!filePtr) {
		cout << "�}�ҿ�J�ɿ��~�I\n";
		system("PAUSE");
		exit(1);	//�D���`�����{��
	} else {
		filePtr.read((char*) this, sizeof(*this));
		while(!filePtr.eof()) {
			showData();
			filePtr.read((char*) this, sizeof(*this));
		}
	}
	filePtr.close();
}

int main(int argc, char** argv)
{
	Student pupil;
	char n;

	while(1)
	{
		cout << "1.�g�J  2.���[  3.Ū��  "	//Menu
			 << "0.����  �п�� (0-3): ";
		cin >> n;
		switch (n)	//�����J��
		{
			case '1':	//�Y��J�Ȭ� 1
				pupil.write();	//�I�s�g�J�G�i���ɨ��
				break;
			case '2':	//�Y��J�Ȭ� 2
				pupil.append();	//�I�s���[�G�i���ɨ��
				break;
			case '3':	//�Y��J�Ȭ� 3
				pupil.read();	//�I�sŪ���G�i���ɨ��
				break;
			case '0':	//�Y��J�Ȭ� 0
				exit(0);	//�����{��
		}
	}
	return 0;
}
