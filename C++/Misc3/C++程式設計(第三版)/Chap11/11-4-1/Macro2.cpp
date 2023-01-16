// Macro2.cpp
// --------------------------------------
#include "Common.h"
#pragma message("注意,這個程式的預設元件數為 10. ")

// ---- 主程式 -------------------------------------
int main()
{
	int a = 3, b = 9;
	double F1= 12.5, F2=8.38;
	cout << "MAX(a, b)   = " << MAX(a, b) 
		<< endl;
	cout << "MAX(F1, F2) = " << MAX(F1, F2) 
		<< endl;
	cout << "PRODUCT(F1, F2) = " 
		<< PRODUCT(F1+2, F2+6)  << endl;
	ShowValue(F1);
	cout << "\n執行 Merge(F,2) 的結果是: " 
		<< Merge(F,2) << endl;  
	system("PAUSE");
	return 0;
}