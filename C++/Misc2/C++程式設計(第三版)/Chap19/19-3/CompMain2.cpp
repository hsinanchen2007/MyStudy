// CompMain2.cpp
// --------------------------------------
#include "CompClass2.h"

int main()
{
	{
		Host H(1,2,3,4);
		cout << "���� sizeof(H)�����G�O: "
			    << sizeof(H)/sizeof(int) << " �� int �ܼ�." << endl;
	}
	system("pause");
	return 0;
}