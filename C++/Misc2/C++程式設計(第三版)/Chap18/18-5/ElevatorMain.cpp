// ElevatorMain.cpp
// --------------------------------------
#include "ElevatorClass.h"

//-------�D�{��-------------------
int main()
{
	{
		// ------(1)------------
		cout << "(1)" << endl;
		Elevator A;                                        // �w�q�q�� A
		cout << "�q 5 �өI�s:" << endl;  
		A.Call(5);                                          // �I�s�q�� A
		A.Select(2);                                       // �]�w�q�� A �� 2 ��
		cout << "�ثe Count���ȬO: " 
			    << A.Count << endl;

		// ------(2)------------
		cout << "(2)" << endl;
		Elevator B(3);                                     // �w�q�q�� B
		cout << "�q 4 �өI�s:" << endl;  
		B.Call(4);                                            // �I�s�q�� B
		B.Select(8);                                         // �]�w�q�� B �� 8 ��
		cout << "�ثe Count ���ȬO: " 
			    << B.Count << endl;
	};
	system("pause");
	return 0;
}
