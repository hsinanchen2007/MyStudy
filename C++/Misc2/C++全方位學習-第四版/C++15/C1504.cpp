//�ɮצW�١Gd:\C++15\C1504.cpp
#include <iostream>
#include <fstream>
#include <cstring>	//�]�tstrlen��Ʃw�q
using namespace std;

const char filename[] = "d:\\C++15\\C1504.txt";

class Note	//�w�qNote���O
{
	char outStr[81];
public:
	void write();	//�ŧi�g�J��r�ɭ쫬
	void append();	//�ŧi���[��r�ɭ쫬
	void read();	//�ŧiŪ����r�ɭ쫬
};

void Note::write()	//�w�q�g�J��r�ɨ��
{
	ofstream filePtr;
	filePtr.open(filename, ios::out);	//�}�ҿ�X��r��
	if(!filePtr) {
		cout << "�}�ҿ�X�ɿ��~�I\n";
		system("PAUSE");
		exit(1);	//�D���`�����{��
	} else {
		cout << "�п�J�r��A�s����G�� Enter �h����\n";
		cin.ignore();	//������J�w�ľ����̫�r
		while(1) {	//�L�a�j��
			cin.getline(outStr, 81);	//Ū������r
			if(!strlen(outStr) == 0)	//�Y�r����פ�����0
				filePtr << outStr << '\n';	//�N��r�g�J�ɮ�
			else
				break;	//���_�j��
		}
	filePtr.close();
	}
}

void Note::append()	//�w�q���[��r�ɨ��
	{
	ofstream filePtr;
	filePtr.open(filename, ios::app);	//�}�Ҫ��[��r��
	if(!filePtr) {
		cout << "�}�Ҫ��[�ɿ��~�I\n";
		system("PAUSE");
		exit(1);	//�D���`�����{��
	} else {
		cout << "�п�J�r��A�s����G�� Enter �h����)\n";
		cin.ignore();	//������J�w�ľ����̫�r
		while(1) {	//�L�a�j��
			cin.getline(outStr, 81);	//Ū������r
			if(!strlen(outStr) == 0)	//�Y�r����פ�����0
				filePtr << outStr << '\n';	//�N��r�g�J�ɮ�
			else
				break;	//���_�j��
		}
	}
	filePtr.close();
}

void Note::read()	//�w�qŪ����r�ɨ��
	{
	ifstream filePtr;
	filePtr.open(filename, ios::in);	//�}�ҿ�J��r��
	char inChar;
	if(!filePtr) {
		cout << "�}�ҿ�J�ɿ��~�I\n";
		system("PAUSE");
		exit(1);	//�D���`�����{��
	} else {
		while(filePtr.get(inChar))	//�YŪ���r�ꤣ����Ŧr��
			cout << inChar;	//��XŪ�����r��
	}
	filePtr.close();
}

int main(int argc, char** argv)
{
	Note text;	//�إ�Note����
	char n;

	while(1)
	{
		cout << "1.�g�J  2.���[  3.Ū��  "	//Menu
			 << "0.����  �п��(1-3��0): ";
		cin >> n;

		switch (n)	//�����J��
		{
			case '1':	//�Y��J�Ȭ�1
				text.write();	//�I�s�g�J��r�ɨ��
				break;
			case '2':	//�Y��J�Ȭ�2
				text.append();	//�I�s���[��r�ɨ��
				break;
			case '3':	//�Y��J�Ȭ�3
				text.read();	//�I�sŪ����r�ɨ��
				break;
			case '0':	//�Y��J�Ȭ�0
				return 0;	//���`�����{��
		}
	}
}
