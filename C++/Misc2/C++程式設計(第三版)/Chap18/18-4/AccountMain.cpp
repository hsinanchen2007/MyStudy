// AccountMain.cpp
#include "AccountClass.h"

//---------- 主程式 --------------------------------
int main()
{
	{
		cout << "\n(1)" << endl;                                 // (1)
		Account John("John"), William("William");  // 定義兩個帳戶
		Account Cathy ("Cathy", 12456);                 // 定義帳戶 Cathy
		Cathy.CheckCount();
		Cathy.WithDraw(450);  		                           // 帳戶 Cathy 提款
		William.Deposit(5000);		                           // 帳戶 Cathy 存款
		cout << "\n(2)" << endl;                                // (2)
		cout << "Size of John is:  "
			<<  sizeof(John)   << endl;
		John.CheckBalance();
		Cathy.CheckBalance();
		William.CheckBalance(); 
		John.WithDraw(450);
		cout << "\n(3)" << endl;
		{                                                         // (3) 區塊開始
			Account Albert("Albert", 1200);   // 定義帳戶 Albert
			Albert.CheckCount();
			Albert.WithDraw(258); 	               // 帳戶 Albert 提款
			Albert.CheckBalance(); 
		}                                                         // (3) 區塊結束
		Cathy.CheckCount();
		cout << "\n(4)" << endl;
		John.CheckRate();
	}

	system("pause");
	return 0;
}
