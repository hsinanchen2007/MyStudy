//�ɮצW�١Gd:\C++11\C1106.cpp
#include <iostream>
#include <cstring>	//���J�r����D��
using namespace std;

class Employee	//�ŧiEmployee���O
{
	int EmpId;
	char name[20];
public:
	void inputEmp()	//�w�qinputEmp���
	{
		cout << "Input EmpId:";
		cin >> EmpId;
		cout << "Input EmpName:";
		cin >> name;
	}
	void outputEmp()	//�w�qoutputEmp���
	{
		cout << "EmpId:" << EmpId << endl;
		cout << "EmpName:" << name << endl;
	}
	Employee()	//�w�q�L�Ѽƫإߪ�
	{
		EmpId = 0;
		strcpy(name, "ZZZ");
	}
	Employee (int id, const char *n)	//�w�q���Ѽƫإߪ�
	{
		EmpId = id;
		strcpy(name, n);
	}
};

int main(int argc, char** argv)
{
	Employee emp1;	//�إߵL�Ѽƪ���
	Employee emp2(123, "TOM");	//�إߦ��Ѽƪ���
	Employee emp3;	//�إߵL�Ѽƪ���

	emp1.outputEmp();	//��ܪ���w�]��
	emp2.outputEmp();	//��ܪ���Ѽƭ�
	cout << endl;
	emp3.inputEmp();	//��ܪ����J��
	emp3.outputEmp();
	return 0;
}
