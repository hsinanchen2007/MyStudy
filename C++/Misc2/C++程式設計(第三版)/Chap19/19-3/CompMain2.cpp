// CompMain2.cpp
// --------------------------------------
#include "CompClass2.h"

int main()
{
	{
		Host H(1,2,3,4);
		cout << "執行 sizeof(H)的結果是: "
			    << sizeof(H)/sizeof(int) << " 個 int 變數." << endl;
	}
	system("pause");
	return 0;
}