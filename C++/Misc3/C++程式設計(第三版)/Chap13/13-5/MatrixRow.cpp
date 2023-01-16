//  MatrixRow.cpp
// --------------------------------------
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

const int M = 4;
const int N = 5;

// ---��ƪ��ŧi------------------------
void  ShowMatrix (double A[][N]);
void  ShowVector (double A[]);
void  PickRow(double A[][N], double B[], int S);
void  SetCol(double A[][N], double B[], int S);

// ---�D�{��----------------------------
int main ()
{
	double M2D[M][N];
	double PickV [N];
	double Data[] = { 1.3, 4.5, 8.32, 45.9, 0.4};
	int PRow = 1;
	int SRow = 2; 
	for (int i = 0; i < M; i++)
		for(int j = 0; j < N ; j++)
			M2D[i][j]= (i+j*j+0.5)/(i+j+2);
	cout << "��Ӫ��x�}�O �G\n";
	ShowMatrix (M2D);
    cout << "��Ӫ��V�q Data �O �G\n";
    ShowVector (Data);
    cout << "�N�x�}���� " << PRow+1 
            << " �C���X���V�q PickV�G\n";
    PickRow(M2D, PickV, PRow);
    ShowVector (PickV);
         
    cout << "�N�x�}���� " << SRow+1 
            << " �C�H�V�q Data ���N��,\n�x�}�����G\n";
    SetCol(M2D, Data, SRow);
    ShowMatrix (M2D);
	system("PAUSE");
	return 0;
}


// ---��� ShowMatrix() ���w�q------------
void  ShowMatrix (double A[][N])
{
	cout << setprecision(4) << right << showpoint << fixed;
    for (int i = 0; i < M; i++)
    {
		cout   << "�� "   << i+1 << " �C�G";
		for(int j = 0; j < N ; j++)
			cout << setw(8) << A[i][j] << " " ;  
		cout << endl;
    }
	cout << endl;
}

// ---��� ShowVector () ���w�q------------
void  ShowVector (double A[])
{
	cout << setprecision(4)  << right
            << showpoint << fixed;
	cout << "�V�q �G  ";
    for(int j = 0; j < N ; j++)
		cout << setw(8) << A[j] << " " ;            
	cout << endl;
	cout << endl;
}

// ---��� PickRow() ���w�q------------
void PickRow(double A[][N], double B[], int S)
{
	for (int i=0; i < N; i++)
		B[i]= A[S][i];
	return ;
}

// ---��� SetCol() ���w�q------------
void SetCol(double A[][N], double B[], int S)
{
	for(int j = 0; j < N ; j++)
		A[S][j]= B[j];
	return;
}
