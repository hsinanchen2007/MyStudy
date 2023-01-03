// ElevatorDef.cpp
// --------------------------------------

#include "ElevatorClass.h"

// --設定 static 變數初始值---------
int   Elevator::Count  = 0; 

// 定義預設建構函數 Account() 
Elevator::Elevator() 
{ 
	cout << "建構函數被呼叫" << endl;
	CurrentFloor = 1; 
	Count++; 
	return;
}

// 定義建構函數 Account() (可設定初值)
Elevator::Elevator(int N) 
{ 
	cout << "建構函數被呼叫" << endl;
	CurrentFloor = N; 
	Count++; 
	return;
}

// 定義解構函數 ~Elevator()
Elevator::~Elevator() 
{ 
	cout << "解構函數被呼叫" << endl;
	Count--;
	return;
}

// --定義成員函數 Call()--------
void Elevator::Call(int N)
{ 
    Move (N);
    cout << "電梯到了, 請進.\n";
    return;
}
  
// --定義成員函數 Select()--------
void Elevator::Select(int N) 
{ 
	cout << "載您到 " << N    << " 樓.\n" ;
    if (N > CurrentFloor)
    	cout << "電梯向上.\n" ;
    else
    	cout << "電梯向下.\n";    
    Move (N);
    cout << "電梯已到 " << CurrentFloor
            << " 樓, 謝謝光臨.\n";
   return;
}

void Elevator::Move(int Target)
{ 
    cout << "電梯門要關了, 請小心." << endl;
    int Start = CurrentFloor;
    cout << "電梯目前在 " << CurrentFloor << " 樓\n";
    if (Target >= CurrentFloor)
    { 
      	for (CurrentFloor  = Start; 
			CurrentFloor <= Target; CurrentFloor++)
			cout << "  燈號: " << CurrentFloor << " 樓\n" ;     
      	            
        CurrentFloor--;
    }
    else
    { 
      	for (CurrentFloor  = Start; 
         CurrentFloor >= Target; CurrentFloor--)
          cout << "  燈號: " << CurrentFloor << " 樓" << endl;   
      	            
        CurrentFloor++;
    }
    cout << "電梯門要開了, 請小心." << endl;
    return;
}


