// Exception.cpp
// --------------------------------------
#include <iostream>
using namespace std;

// --- ��� Divide() ���쫬 -----
float Divide(float, float);

// ----�D�{��-----------------------
int main()
{
	float M, N;
	try
	{
		cout << "�п�J��ӼƦr,\n" << endl;
		cout << "�п�J�Ĥ@�ӼƦr :" << endl;
		 cin  >> M;
		cout << "�п�J�ĤG�ӼƦr :" << endl;
		 cin  >> N;
		cout << "�z��J�F : " << M << " �M " << N << endl;
		cout << "�o��ӼƦr�۰������G�O: "
			    << Divide(M,N) << endl;
	}

	catch (char* pError)
	{
		cerr << "�o�Ͳ��`: " << pError << endl;
	}
	system("PAUSE");
	return 0;
}

