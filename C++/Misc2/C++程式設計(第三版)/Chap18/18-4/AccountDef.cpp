// AccountDef.cpp
#include "AccountClass.h"
#include <cstring>

// -- �]�w static �ܼƪ�l�� --------------------------
float Account::Rate  = 5.8;
int   Account::Count = 0;

//-- �w�q�w�]�غc��� Account() ------------ ----------
Account::Account()
{ 
     cout << "�]�w�Ȧ�b��" << endl;
     Balance = 0; 
     Account::Count++;
     cout << "�ثe�|����J�b��W��.\n";
     return;
}
//-- �w�q�غc��� Account() ----------------------------
Account::Account(char Name[])
{ 
     strcpy(Id, Name);
     cout << "�]�w " << left << setw(8) << Id 
             << " ���Ȧ�b��" << endl;
     Balance = 0; 
     Account::Count++;
     cout << "�ثe " << setw(8) << Id << " �b��l�B�O "
             << Balance << " ��\n";
     return;
}
// -- �w�q�غc��� Account() (�i�]�w���) --------------
Account::Account(char Name[], int N)
{ 
     strcpy(Id, Name);
     cout << "�]�w " << setw(8) << Id << " ���Ȧ�b��" << endl;
     Balance = N; 
     Account::Count++;
     cout << "�ثe " << setw(8) << Id << " �b��l�B�O "
             << Balance << " ��\n";
     return;
}
//-- �w�q�Ѻc��� ~Account() -------------------------
Account::~Account()
{ 
     cout << "���� " << setw(8) << Id << " ���Ȧ�b��" << endl;
     Account::Count--;
     return;
}
// -- �w�q������� WithDraw() ------------------------
void Account::WithDraw(int Cash)
{ 
    if (Cash > Balance)
      { 
			cerr <<  "�s�ڤ���! " << setw(8) << Id 
					<< " �o�����ڤ���." << endl;	
			return;
      }
    Balance -= Cash;
    cout << setw(8) << Id << " ���� " << Cash << " ����A"
			<< "�ثe�b��l�B�O " << Balance << " ��\n";
    return;
}