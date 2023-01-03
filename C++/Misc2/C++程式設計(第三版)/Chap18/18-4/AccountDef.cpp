// AccountDef.cpp
#include "AccountClass.h"
#include <cstring>

// -- 設定 static 變數初始值 --------------------------
float Account::Rate  = 5.8;
int   Account::Count = 0;

//-- 定義預設建構函數 Account() ------------ ----------
Account::Account()
{ 
     cout << "設定銀行帳戶" << endl;
     Balance = 0; 
     Account::Count++;
     cout << "目前尚未輸入帳戶名稱.\n";
     return;
}
//-- 定義建構函數 Account() ----------------------------
Account::Account(char Name[])
{ 
     strcpy(Id, Name);
     cout << "設定 " << left << setw(8) << Id 
             << " 的銀行帳戶" << endl;
     Balance = 0; 
     Account::Count++;
     cout << "目前 " << setw(8) << Id << " 帳戶餘額是 "
             << Balance << " 元\n";
     return;
}
// -- 定義建構函數 Account() (可設定初值) --------------
Account::Account(char Name[], int N)
{ 
     strcpy(Id, Name);
     cout << "設定 " << setw(8) << Id << " 的銀行帳戶" << endl;
     Balance = N; 
     Account::Count++;
     cout << "目前 " << setw(8) << Id << " 帳戶餘額是 "
             << Balance << " 元\n";
     return;
}
//-- 定義解構函數 ~Account() -------------------------
Account::~Account()
{ 
     cout << "徹消 " << setw(8) << Id << " 的銀行帳戶" << endl;
     Account::Count--;
     return;
}
// -- 定義成員函數 WithDraw() ------------------------
void Account::WithDraw(int Cash)
{ 
    if (Cash > Balance)
      { 
			cerr <<  "存款不足! " << setw(8) << Id 
					<< " 這次提款不成." << endl;	
			return;
      }
    Balance -= Cash;
    cout << setw(8) << Id << " 提款 " << Cash << " 元後，"
			<< "目前帳戶餘額是 " << Balance << " 元\n";
    return;
}