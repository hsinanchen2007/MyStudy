// AccountClass.h
#ifndef ACCOUNTCLASS_H
#define ACCOUNTCLASS_H
#include <iostream>
#include <iomanip>
using namespace::std;

//---- �ŧi���O Account -----------------------------
class Account
{
	private:
		static float Rate;    // static �ܼ�
		static int   Count;   // static �ܼ�
		int          Balance;
		char         Id[20];

	public:
		Account();                  // �w�]�غc���
		Account(char[]);        // �غc���-1
		Account(char[], int);  // �غc���-2
		~Account();   	           // �Ѻc���
		void Deposit (int);
		void WithDraw(int);
		void CheckBalance() const;
		void CheckRate   () const
		{cout << "�ثe�s�ڧQ�v�O: " << Rate << '%' << endl;}
		void CheckCount() const;
};

// -- �w�q inline ������� Deposit() ------------------
inline void Account::Deposit(int CashInput)
{ 
    Balance += CashInput;
    cout << setw(8) << Id << " �s�� " << CashInput 
            << " ���� " << "�ثe�b��l�B�O " 
            << Balance << " ��\n";
    return;
}

// -- �w�q inline ������� CheckBalance() -------------
inline void Account::CheckBalance() const
{ 
     cout << "�ثe " << setw(8) << Id 
             << " ���b��l�B�O " << Balance << " ��\n";
     return;
}

// -- �w�q inline ������� CheckCount() ----------------
inline void Account::CheckCount() const
{ 
     cout << "�ثe�Ȧ�@�� " << Count << " �ӱb��.\n"; 
     return;
}

#endif
