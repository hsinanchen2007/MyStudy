// FEDef.cpp
// --------------------------------------
#include "FEClass.h"

// --設定 static 變數初始值---------
int   Elevator::Count  = 0; 

// --定義 friend 函數 Call()--------
void Call(Elevator& E, int N)
{ 
    E.Move (N);
    cout << "電梯到了, 請進." << endl;
    return;
}
  
// --定義 friend 函數 Select()--------
void Select(Elevator& E, int N) 
{ 
    cout << "載您到 " << N    << " 樓." << endl;
    if (N > E.CurrentFloor)
		cout << "電梯向上."   << endl;
    else
    	cout << "電梯向下."   << endl;    
    E.Move (N);
    cout << "電梯已到 " << E.CurrentFloor
            << " 樓, 謝謝光臨." << endl;
    return;
}

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


void Elevator::Move(int Target)
{ 
    cout << "電梯門要關了, 請小心." << endl;
    int Start = CurrentFloor;
    cout << "電梯目前在 " << CurrentFloor
      	    << " 樓"                 << endl;
    if (Target >= CurrentFloor)
    { 
      	for (CurrentFloor  = Start; 
			CurrentFloor <= Target; CurrentFloor++)
          cout << "  燈號: " << CurrentFloor
      	          << " 樓"        << endl;      
        CurrentFloor--;
    }
    else
    { 
      	for (CurrentFloor  = Start; 
			CurrentFloor >= Target; CurrentFloor--)
          cout << "  燈號: " << CurrentFloor
      	          << " 樓"        << endl;      
        CurrentFloor++;
    }
    cout << "電梯門要開了, 請小心." << endl;
    return;
}


