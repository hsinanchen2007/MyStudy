//�ɮצW�١Gd:\C++15\C1505.cpp
#include <iostream>
#include <fstream>
using namespace std;

class Student	//�w�qStudent���O
{
protected:		//�O�@��
	int student_id;
	char student_name[40];
public:			//���ΰ�
	int getid()	//���o�Ǹ����
	{
		return student_id;
	}
	void setdata()	//��J�üg�J�w�İϨ��
	{
		cout << "�п�J�Ǹ��P�m�W (��J 0 0 �h����)�G";
		cin >> student_id >> student_name;	//��J�Ǹ��P�m�W
	}
};

int main(int argc, char** argv)
{
	Student stuData;	//�إ����O����
	ofstream filePtr;	//�إ߿�X�ɮת���
	filePtr.open("d:\\C++15\\C1505.dat", ios::binary);	//�}�ҤG�i����

	if(!filePtr) {	//�Y�ɮץN�����~
		cout << "�}���ɮ׿��~�I\n";
		system("PAUSE");
		exit(1);	//�D���`�����{��
	} else {		//�h
		while(1) {	//��J�üg�J��ưj��
			stuData.setdata();	//��J��ƨ�w�İ�
			if(stuData.getid() != 0)	//�Y�Ǹ�������0�h
				filePtr.write((char*)&stuData,	//�w�İϸ�Ƽg�J�ɮ�
				    sizeof(stuData));	//�g�J����=�w�İϤj�p
			else	//�Y�Ǹ�����0�h
				break;	//������J
		}
	}
	filePtr.close();
	return 0;
}
