//�ɮצW�١Gd:\C++16\C1602.cpp
#include <iostream>
using namespace std;

void check(char i)	//�t��throw�����
{
	if (i<'0' || i>'9') throw i;	//�Y��J�W�X0-9�hthrow
	cout << "��J�� = " << i << endl;	//��ܿ�J��
}

int main(int argc, char** argv)
{
	char n;
	while (1)
	{
		cout << "�п�J0 - 9 ����ơG";
		cin >> n;
		try {			//try
			check(n);	//�I�scheck���
		}
		catch(char i) {	//chtch
			cout << "��J�� = " << i << "�A�W�X�d��I\n";	//��ܰT��
			return 1;	//�D���`�����{��
		}
	}
	return 0;	//���`�����{�� 
}
