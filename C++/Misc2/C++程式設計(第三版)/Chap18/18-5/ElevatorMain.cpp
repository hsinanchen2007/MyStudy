// ElevatorMain.cpp
// --------------------------------------
#include "ElevatorClass.h"

//-------主程式-------------------
int main()
{
	{
		// ------(1)------------
		cout << "(1)" << endl;
		Elevator A;                                        // 定義電梯 A
		cout << "從 5 樓呼叫:" << endl;  
		A.Call(5);                                          // 呼叫電梯 A
		A.Select(2);                                       // 設定電梯 A 到 2 樓
		cout << "目前 Count的值是: " 
			    << A.Count << endl;

		// ------(2)------------
		cout << "(2)" << endl;
		Elevator B(3);                                     // 定義電梯 B
		cout << "從 4 樓呼叫:" << endl;  
		B.Call(4);                                            // 呼叫電梯 B
		B.Select(8);                                         // 設定電梯 B 到 8 樓
		cout << "目前 Count 的值是: " 
			    << B.Count << endl;
	};
	system("pause");
	return 0;
}
