//�x�s�ɦW�Gd:\C++18\C1801.cpp
#include <iostream>
#include <iomanip>
using namespace std;

long factorial(int);

int main(int argc, char** argv)
{
	int count = 1;	//while �j����
	cout << "�p��\t" << setw(8) << "����\n";	//��X�r��
	do {
		cout << setw(3) << count << '\t';	//��X�p�ƭ�
		cout << setw(7) << factorial(count) << endl;	//��X����
	} while(++count<=10);
	return 0;
}

long factorial(int n)
{
	if(n>1)
		return n * factorial(n-1);
	else
		return 1;
}
