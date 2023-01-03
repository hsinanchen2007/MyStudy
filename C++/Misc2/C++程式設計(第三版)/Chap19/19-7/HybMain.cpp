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
	  cout << "���� �uHybrid x�v      ����: " << endl;
	  Hybrid x;
	  cout << "x.Get()    :   " << x.Get()     << endl;
	  cout << "x.GetBase():   " << x.GetBase() << endl;
	  cout << "x.GetC1()  :   " << x.GetC1()   << endl;
	  cout << "x.GetC2()  :   " << x.GetC2()   << endl;
	  cout << "���� �ux.Double()�v    ����: "  << endl;
	  x.Double();
	  cout << "x.Get()    :   " << x.Get()     << endl;
	  cout << "x.GetBase():   " << x.GetBase() << endl;
	  cout << "x.GetC1()  :   " << x.GetC1()   << endl;
	  cout << "x.GetC2()  :   " << x.GetC2()   << endl;
	  cout << "���� �ux.DoubleBase()�v����: "  << endl;
	  x.DoubleBase();
	  cout << "x.Get()    :   " << x.Get()     << endl;
	  cout << "x.GetBase():   " << x.GetBase() << endl;
	  cout << "x.GetC1()  :   " << x.GetC1()   << endl;
	  cout << "x.GetC2()  :   " << x.GetC2()   << endl;
	  cout << "���� �ux.DoubleComp()�v����: "  << endl;
	  x.DoubleComp();
	  cout << "x.Get()    :   " << x.Get()     << endl;
	  cout << "x.GetBase():   " << x.GetBase() << endl;
	  cout << "x.GetC1()  :   " << x.GetC1()   << endl;
	  cout << "x.GetC2()  :   " << x.GetC2()   << endl;
	  cout << "���� �uHybrid y(7,8,9,10)�v����: " << endl;
	  Hybrid y(7,8,9,10);
	  cout << "y.Get()    :   " << y.Get()     << endl;
	  cout << "y.GetBase():   " << y.GetBase() << endl;
	  cout << "y.GetC1()  :   " << y.GetC1()   << endl;
	  cout << "y.GetC2()  :   " << y.GetC2()   << endl;
	};
  system("pause");
  return 0;
}
	