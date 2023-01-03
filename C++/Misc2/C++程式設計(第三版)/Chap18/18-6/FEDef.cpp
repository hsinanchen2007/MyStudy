// FEDef.cpp
// --------------------------------------
#include "FEClass.h"

// --�]�w static �ܼƪ�l��---------
int   Elevator::Count  = 0; 

// --�w�q friend ��� Call()--------
void Call(Elevator& E, int N)
{ 
    E.Move (N);
    cout << "�q���F, �жi." << endl;
    return;
}
  
// --�w�q friend ��� Select()--------
void Select(Elevator& E, int N) 
{ 
    cout << "���z�� " << N    << " ��." << endl;
    if (N > E.CurrentFloor)
		cout << "�q��V�W."   << endl;
    else
    	cout << "�q��V�U."   << endl;    
    E.Move (N);
    cout << "�q��w�� " << E.CurrentFloor
            << " ��, ���¥��{." << endl;
    return;
}

// �w�q�w�]�غc��� Account() 
Elevator::Elevator() 
{ 
	cout << "�غc��ƳQ�I�s" << endl;
	CurrentFloor = 1; 
	Count++; 
	return;
}

// �w�q�غc��� Account() (�i�]�w���)
Elevator::Elevator(int N) 
{ 
	cout << "�غc��ƳQ�I�s" << endl;
	CurrentFloor = N; 
	Count++; 
	return;
}

// �w�q�Ѻc��� ~Elevator()
Elevator::~Elevator() 
{ 
	cout << "�Ѻc��ƳQ�I�s" << endl;
	Count--;
	return;
}


void Elevator::Move(int Target)
{ 
    cout << "�q����n���F, �Фp��." << endl;
    int Start = CurrentFloor;
    cout << "�q��ثe�b " << CurrentFloor
      	    << " ��"                 << endl;
    if (Target >= CurrentFloor)
    { 
      	for (CurrentFloor  = Start; 
			CurrentFloor <= Target; CurrentFloor++)
          cout << "  �O��: " << CurrentFloor
      	          << " ��"        << endl;      
        CurrentFloor--;
    }
    else
    { 
      	for (CurrentFloor  = Start; 
			CurrentFloor >= Target; CurrentFloor--)
          cout << "  �O��: " << CurrentFloor
      	          << " ��"        << endl;      
        CurrentFloor++;
    }
    cout << "�q����n�}�F, �Фp��." << endl;
    return;
}


