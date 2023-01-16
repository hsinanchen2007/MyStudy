// EnumEx.cpp
// --------------------------------------
#include <iostream>
using namespace std;

// - 函數 ShowVectorElement() 的原型
float ShowVectorElement(float [],int);
// 定義 enum資料型態ErrorStates
enum ErrorStates {OK, OverFlow, UnderFlow};

// ----主程式-----------------------
int main()
{
	const int Size = 5;
	float V[Size];
	int M;
	for (int i=0; i< Size; i++)
		V[i] = float(0.5+ i*i)/2.5;

	try
	{
		cout << "請輸入一個數字(在 0 至 "
			    << Size << " 範圍內):" << endl;
		 cin  >> M;
		cout << "您輸入了: " 
			    << M    <<  endl;
		cout << "V[" << M  << "]" << " 的值是: "
			    << ShowVectorElement(V, M) << endl;
	}
	catch (ErrorStates Error)
	{
		if (Error==OverFlow)
			cerr << "發生異常: OverFlow" << endl;			
		if (Error==UnderFlow)
			cerr << "發生異常: UnderFlow" << endl;     
	}
	catch (...) 
	{cerr   << "發生了預計範圍之外的異常!" << endl; }      
	
	system("PAUSE");
	return 0;
}

