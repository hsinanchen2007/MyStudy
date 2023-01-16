// SaveMatrix.cpp
// --------------------------------------
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

const int M = 4;
const int N = 5;

// ---��� RecMatrix () ���ŧi------
void RecMatrix (char *, double [][N], int, int);

// ---�D�{��--------------------------
int main ()
{
	double Matrix[M][N];
	char *FileName   = "Record.txt";
	for (int i = 0; i < M; i++)
		for(int j = 0; j < N ; j++)
			Matrix[i][j]= (i+j*j+0.5)/(i+j+2);
	char Ch;
	cout << "�A�n�N�x�}�s�b " << FileName
			<< " ����? (Y/N)" <<endl;
	cin    >> Ch;
	if (Ch == 'Y' || Ch == 'y')
		RecMatrix (FileName, Matrix, M, N);
	else
		cout << "�S���s��." << endl;
	system("PAUSE");
	return 0;
}

// ---��� RecMatrix () ���w�q--------
void  RecMatrix (char *FileNameOut,
        double A[][N], int M, int N)
{
	ofstream FileOutput;
	FileOutput.open( FileNameOut, ios::out);
	if (!FileOutput)
		{ cout << "�ɮ�: " << FileNameOut
                   << " �s�ɥ���!" << endl; exit(1);}
    FileOutput << setprecision(4)  << right
                      << showpoint         << fixed;
	for (int i = 0; i < M; i++)
    {
		FileOutput  << "�� " << i+1 << " �C�G";
		for(int j = 0; j < N ; j++)
			FileOutput  << setw(8) << A[i][j] << " " ;
		FileOutput << endl;
    }
	FileOutput.close();
	cout << "�w�g�s���ɮ� "
			<< FileNameOut << " ��." << endl;
}
