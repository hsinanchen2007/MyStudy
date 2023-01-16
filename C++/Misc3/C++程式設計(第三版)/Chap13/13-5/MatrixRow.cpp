//  MatrixRow.cpp
// --------------------------------------
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

const int M = 4;
const int N = 5;

// ---ㄧ计------------------------
void  ShowMatrix (double A[][N]);
void  ShowVector (double A[]);
void  PickRow(double A[][N], double B[], int S);
void  SetCol(double A[][N], double B[], int S);

// ---祘Α----------------------------
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
	cout << "ㄓ痻皚琌 \n";
	ShowMatrix (M2D);
    cout << "ㄓ秖 Data 琌 \n";
    ShowVector (Data);
    cout << "盢痻皚材 " << PRow+1 
            << " Θ秖 PickV\n";
    PickRow(M2D, PickV, PRow);
    ShowVector (PickV);
         
    cout << "盢痻皚材 " << SRow+1 
            << " 秖 Data ,\n痻皚Θ\n";
    SetCol(M2D, Data, SRow);
    ShowMatrix (M2D);
	system("PAUSE");
	return 0;
}


// ---ㄧ计 ShowMatrix() ﹚竡------------
void  ShowMatrix (double A[][N])
{
	cout << setprecision(4) << right << showpoint << fixed;
    for (int i = 0; i < M; i++)
    {
		cout   << "材 "   << i+1 << " ";
		for(int j = 0; j < N ; j++)
			cout << setw(8) << A[i][j] << " " ;  
		cout << endl;
    }
	cout << endl;
}

// ---ㄧ计 ShowVector () ﹚竡------------
void  ShowVector (double A[])
{
	cout << setprecision(4)  << right
            << showpoint << fixed;
	cout << "秖   ";
    for(int j = 0; j < N ; j++)
		cout << setw(8) << A[j] << " " ;            
	cout << endl;
	cout << endl;
}

// ---ㄧ计 PickRow() ﹚竡------------
void PickRow(double A[][N], double B[], int S)
{
	for (int i=0; i < N; i++)
		B[i]= A[S][i];
	return ;
}

// ---ㄧ计 SetCol() ﹚竡------------
void SetCol(double A[][N], double B[], int S)
{
	for(int j = 0; j < N ; j++)
		A[S][j]= B[j];
	return;
}
