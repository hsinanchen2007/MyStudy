// Reserved.cpp
// --------------------------------------
#include <iostream>
using namespace std;
// ---- �D�{�� -------------------------------------
int main()
{
	cout << "�渹    : " << __LINE__ << endl;
	cout << "�ɦW    : " << __FILE__ << endl;
	cout << "�sĶ���: " << __DATE__ << endl;
	cout << "�sĶ�ɶ�: " << __TIME__ << endl;
	#line 120 "Test File.cpp"       
	cout << "���� #line 120 \"Test File.cpp\"����: "
		    << endl; 
	cout << "�渹    : " << __LINE__ << endl;
	cout << "�ɦW    : " << __FILE__ << endl;
	system("PAUSE");
	return 0;   
}
