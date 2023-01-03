// BAndD2.cpp
// --------------------------------------
#include "BD2.h"
int main()
{
	{
	  cout << "執行 「Derived X;」        之後: "  << endl;
	  Derived X;
	  cout << endl;
	  cout << "執行 「Derived Y(12,25);」 之後: " << endl;
	  Derived Y(12,25);
	};
  system("pause");
  return 0;
}
