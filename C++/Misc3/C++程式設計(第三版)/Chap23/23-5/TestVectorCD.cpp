// TestVectorCD.cpp
#include "VectorCD.h"

int main()
{
	cout << "(1)°õ¦æ" <<
		"¡uVector<double>* pV = new Vector<double>[5];¡v:"
		<< endl;
	Vector<double>* pV = new Vector<double>[5];
	cout << endl;
	cout <<  "(2)°õ¦æ ¡udelete [] pV;¡v:" << endl;
	delete [] pV;
	int* pI = new int[8];
	delete [] pI;
	system("pause");
	return 0;
}
