//�ɮצW�١Gd:\C++16\C1601.cpp
#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
	char ps[9] = "year2021";
	char str[9];
	cout << "�п�J�K�X�G";
	cin >> str;
	try {
		for(int i=0; i<9; i++)
			if (str[i] != ps[i])	//�Y�K�X���~
				throw i;	//�h���Y�ҥ~
		cout << "�K�X���T�I\n";	//��ܥ��T�T��
	}
	catch(int i) {	//�����ҥ~
		cout << "�K�X���~�I\n";	//��ܿ��~�T��
	}
	return 0;
}
