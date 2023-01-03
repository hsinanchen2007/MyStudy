// HybMain.cpp
// --------------------------------------
#include "HybClass.h"

int main()
{
	{
	  cout << "sizeof(Component)/sizeof(int): " 
			  << sizeof(Component)/sizeof(int) << endl;
	  cout << "sizeof(Base)/sizeof(int)     : " 
			  << sizeof(Base)/sizeof(int) << endl;
	  cout << "sizeof(Hybrid)/sizeof(int)   : "
			  << sizeof(Hybrid)/sizeof(int) << endl;
	  cout << "執行 「Hybrid x」      之後: " << endl;
	  Hybrid x;
	  cout << "x.Get()    :   " << x.Get()     << endl;
	  cout << "x.GetBase():   " << x.GetBase() << endl;
	  cout << "x.GetC1()  :   " << x.GetC1()   << endl;
	  cout << "x.GetC2()  :   " << x.GetC2()   << endl;
	  cout << "執行 「x.Double()」    之後: "  << endl;
	  x.Double();
	  cout << "x.Get()    :   " << x.Get()     << endl;
	  cout << "x.GetBase():   " << x.GetBase() << endl;
	  cout << "x.GetC1()  :   " << x.GetC1()   << endl;
	  cout << "x.GetC2()  :   " << x.GetC2()   << endl;
	  cout << "執行 「x.DoubleBase()」之後: "  << endl;
	  x.DoubleBase();
	  cout << "x.Get()    :   " << x.Get()     << endl;
	  cout << "x.GetBase():   " << x.GetBase() << endl;
	  cout << "x.GetC1()  :   " << x.GetC1()   << endl;
	  cout << "x.GetC2()  :   " << x.GetC2()   << endl;
	  cout << "執行 「x.DoubleComp()」之後: "  << endl;
	  x.DoubleComp();
	  cout << "x.Get()    :   " << x.Get()     << endl;
	  cout << "x.GetBase():   " << x.GetBase() << endl;
	  cout << "x.GetC1()  :   " << x.GetC1()   << endl;
	  cout << "x.GetC2()  :   " << x.GetC2()   << endl;
	  cout << "執行 「Hybrid y(7,8,9,10)」之後: " << endl;
	  Hybrid y(7,8,9,10);
	  cout << "y.Get()    :   " << y.Get()     << endl;
	  cout << "y.GetBase():   " << y.GetBase() << endl;
	  cout << "y.GetC1()  :   " << y.GetC1()   << endl;
	  cout << "y.GetC2()  :   " << y.GetC2()   << endl;
	};
  system("pause");
  return 0;
}
	