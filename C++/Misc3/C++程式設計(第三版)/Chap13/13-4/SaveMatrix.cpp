// SaveMatrix.cpp
// --------------------------------------
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

const int M = 4;
const int N = 5;

// ---函數 RecMatrix () 的宣告------
void RecMatrix (char *, double [][N], int, int);

// ---主程式--------------------------
int main ()
{
	double Matrix[M][N];
	char *FileName   = "Record.txt";
	for (int i = 0; i < M; i++)
		for(int j = 0; j < N ; j++)
			Matrix[i][j]= (i+j*j+0.5)/(i+j+2);
	char Ch;
	cout << "你要將矩陣存在 " << FileName
			<< " 中嗎? (Y/N)" <<endl;
	cin    >> Ch;
	if (Ch == 'Y' || Ch == 'y')
		RecMatrix (FileName, Matrix, M, N);
	else
		cout << "沒有存檔." << endl;
	system("PAUSE");
	return 0;
}

// ---函數 RecMatrix () 的定義--------
void  RecMatrix (char *FileNameOut,
        double A[][N], int M, int N)
{
	ofstream FileOutput;
	FileOutput.open( FileNameOut, ios::out);
	if (!FileOutput)
		{ cout << "檔案: " << FileNameOut
                   << " 存檔失敗!" << endl; exit(1);}
    FileOutput << setprecision(4)  << right
                      << showpoint         << fixed;
	for (int i = 0; i < M; i++)
    {
		FileOutput  << "第 " << i+1 << " 列：";
		for(int j = 0; j < N ; j++)
			FileOutput  << setw(8) << A[i][j] << " " ;
		FileOutput << endl;
    }
	FileOutput.close();
	cout << "已經存於檔案 "
			<< FileNameOut << " 內." << endl;
}
