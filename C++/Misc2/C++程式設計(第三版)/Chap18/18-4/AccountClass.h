// AccountClass.h
#ifndef ACCOUNTCLASS_H
#define ACCOUNTCLASS_H
#include <iostream>
#include <iomanip>
using namespace::std;

//---- 摸 Account -----------------------------
class Account
{
	private:
		static float Rate;    // static 跑计
		static int   Count;   // static 跑计
		int          Balance;
		char         Id[20];

	public:
		Account();                  // 箇砞篶ㄧ计
		Account(char[]);        // 篶ㄧ计-1
		Account(char[], int);  // 篶ㄧ计-2
		~Account();   	           // 秆篶ㄧ计
		void Deposit (int);
		void WithDraw(int);
		void CheckBalance() const;
		void CheckRate   () const
		{cout << "ヘ玡蹿瞯琌: " << Rate << '%' << endl;}
		void CheckCount() const;
};

// -- ﹚竡 inline Θㄧ计 Deposit() ------------------
inline void Account::Deposit(int CashInput)
{ 
    Balance += CashInput;
    cout << setw(8) << Id << " 蹿 " << CashInput 
            << " じ " << "ヘ玡眀め緇肂琌 " 
            << Balance << " じ\n";
    return;
}

// -- ﹚竡 inline Θㄧ计 CheckBalance() -------------
inline void Account::CheckBalance() const
{ 
     cout << "ヘ玡 " << setw(8) << Id 
             << " 眀め緇肂琌 " << Balance << " じ\n";
     return;
}

// -- ﹚竡 inline Θㄧ计 CheckCount() ----------------
inline void Account::CheckCount() const
{ 
     cout << "ヘ玡蝗︽Τ " << Count << " 眀め.\n"; 
     return;
}

#endif
