// AccountMain.cpp
#include "AccountClass.h"

//---------- �D�{�� --------------------------------
int main()
{
	{
		cout << "\n(1)" << endl;                                 // (1)
		Account John("John"), William("William");  // �w�q��ӱb��
		Account Cathy ("Cathy", 12456);                 // �w�q�b�� Cathy
		Cathy.CheckCount();
		Cathy.WithDraw(450);  		                           // �b�� Cathy ����
		William.Deposit(5000);		                           // �b�� Cathy �s��
		cout << "\n(2)" << endl;                                // (2)
		cout << "Size of John is:  "
			<<  sizeof(John)   << endl;
		John.CheckBalance();
		Cathy.CheckBalance();
		William.CheckBalance(); 
		John.WithDraw(450);
		cout << "\n(3)" << endl;
		{                                                         // (3) �϶��}�l
			Account Albert("Albert", 1200);   // �w�q�b�� Albert
			Albert.CheckCount();
			Albert.WithDraw(258); 	               // �b�� Albert ����
			Albert.CheckBalance(); 
		}                                                         // (3) �϶�����
		Cathy.CheckCount();
		cout << "\n(4)" << endl;
		John.CheckRate();
	}

	system("pause");
	return 0;
}
