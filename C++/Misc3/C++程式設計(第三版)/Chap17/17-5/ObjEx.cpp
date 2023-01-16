// ObjEx.cpp
// --------------------------------------
#include "Common.h"
using namespace ExcNameSpace;

// ----�D�{��-----------------------
int main()
{
	const int Size = 5;
	float V[Size];
	int M;
	for (int i=0; i< Size; i++)
		V[i] = float(0.5+ i*i)/2.5;

	try
	{
		cout << "�п�J�@�ӼƦr(�b 0 �� " << Size << " �d��):" << endl;
		 cin  >> M;
		cout << "�z��J�F: "	<< M    <<  endl;	
		cout << "V[" << M  << "]" << " ���ȬO: "
			    << ShowVectorElement(V, M) << endl;
	}
	catch (OverFlow)
	{ 
		cerr << "�o�Ͳ��`: OverFlow" << endl;
	}
	catch (UnderFlow)
	{ 
		cerr << "�o�Ͳ��`: UnderFlow" << endl;
	}
	catch (...)
	{ 
		cerr << "�o�ͤF�w�p�d�򤧥~�����`!" << endl;
	}
	system("PAUSE");
	return 0;
}

