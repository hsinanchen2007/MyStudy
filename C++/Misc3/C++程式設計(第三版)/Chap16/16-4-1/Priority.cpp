// Priority.cpp
// --------------------------------------
#include <iostream>
using namespace std;

namespace NS     // �ŧi�W�٪Ŷ� NS
{
	int M = 10;                   // (1)
	float x =1.0,  y = 2.0;   // (2)
	char C = 'G';                 // (3)
}

// ----�D�{��-----------------------
int main()
{
	NS::M = 6;                       //  ���(1)����M
	{
		float y = 7.5;                //  (4)�w�q�����ܼ� y
		using namespace NS;   //  using ���O
		x = 5.6;                        //  ���(2) ���� x
		cout << y <<endl;	     //  ��X(4) ���� y (=7.5)
	}
	//C = 'P';      // ���~!���B�w�L�k���� (3) ���� C 
	system("PAUSE");
	return 0;
}