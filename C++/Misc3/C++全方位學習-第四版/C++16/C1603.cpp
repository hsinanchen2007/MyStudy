//�ɮצW�١Gd:\C++16\C1603.cpp
#include <iostream>
using namespace std;

bool check(char i)	//�t��throw�����
{
	try {			//try
		if (i<'0' || i>'9') throw i;	//�Y��J�W�X0-9�hthrow
		cout << "��J�� = " << i << endl;	//��ܿ�J��
		return true;
	} catch(char i) {	//chtch
		cout << "��J�� = " << i << "�A�W�X�d��I\n";	//��ܰT��
		return false;
	}
}

int main(int argc, char** argv)
{
	char n;
	do
	{
		cout << "�п�J0 - 9 ����ơG";
		cin >> n;
	} while(check(n));	//�I�scheck���
	return 0;
}
