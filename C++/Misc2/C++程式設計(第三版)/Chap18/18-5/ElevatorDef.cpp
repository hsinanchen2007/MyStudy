// ElevatorDef.cpp
// --------------------------------------

#include "ElevatorClass.h"

// --�]�w static �ܼƪ�l��---------
int   Elevator::Count  = 0; 

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

// --�w�q������� Call()--------
void Elevator::Call(int N)
{ 
    Move (N);
    cout << "�q���F, �жi.\n";
    return;
}
  
// --�w�q������� Select()--------
void Elevator::Select(int N) 
{ 
	cout << "���z�� " << N    << " ��.\n" ;
    if (N > CurrentFloor)
    	cout << "�q��V�W.\n" ;
    else
    	cout << "�q��V�U.\n";    
    Move (N);
    cout << "�q��w�� " << CurrentFloor
            << " ��, ���¥��{.\n";
   return;
}

void Elevator::Move(int Target)
{ 
    cout << "�q����n���F, �Фp��." << endl;
    int Start = CurrentFloor;
    cout << "�q��ثe�b " << CurrentFloor << " ��\n";
    if (Target >= CurrentFloor)
    { 
      	for (CurrentFloor  = Start; 
			CurrentFloor <= Target; CurrentFloor++)
			cout << "  �O��: " << CurrentFloor << " ��\n" ;     
      	            
        CurrentFloor--;
    }
    else
    { 
      	for (CurrentFloor  = Start; 
         CurrentFloor >= Target; CurrentFloor--)
          cout << "  �O��: " << CurrentFloor << " ��" << endl;   
      	            
        CurrentFloor++;
    }
    cout << "�q����n�}�F, �Фp��." << endl;
    return;
}


