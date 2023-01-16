// Matrix.h

#ifndef Matrix_H
#define Matrix_H

#include <iostream>
#include <iomanip>
using namespace std;

// == 宣告 Matrix 樣版類別 ===============
template <class T>
class Matrix
{ 
  private:
    int M, N;
    T** A;
    void Create(int, int);
  public:
    // 宣告建構函數
    Matrix(int, int);
    Matrix(int, int, const T*);
    // 宣告複製建構函數
    Matrix(Matrix<T>&);
    // 宣告解構函數
    ~Matrix();
    //operator
    // 宣告指派運算子 operator = ()
    Matrix<T> operator=(const Matrix<T>&);
    // 宣告加法運算子 operator + ()
    Matrix<T> operator+(const Matrix<T>&);
    // 宣告乘法運算子 operator * ()
    Matrix<T> operator*(const Matrix<T>&);
    // 宣告索引運算子 operator [] ()
    T* operator[](int i){return A[i];}
    // 宣告成員函數 SetCol()
    void SetCol(int, Vector<T>&);
    // 宣告成員函數 PickCol()
    Vector<T> PickCol(int);
    // 宣告成員函數 Display()
    void Display();
};

// =======  成員函數的定義  ================
// 函數 Create() 的定義
template <class T>
void Matrix<T>::Create(int Row, int Col)
{
  Check((Row<1)||(Col<1),
    "矩陣建構錯誤, 行列大小不能為負值!");
  M = Row;
  N = Col;
  A = new T* [M+1];
  A[0]= new T[M*N+1];
  A[1]= A[0];
  for(int i=2; i<= M; i++)
     A[i]=A[i-1]+N;
}

// 建構函數的定義
template <class T>
Matrix<T>::Matrix(int Row, int Col)
   { Create(Row,Col);  return;}


// 建構函數的定義 (從一維陣列建立二維陣列)
template <class T>
Matrix<T>::Matrix(int Row, int Col, const T* V)
{ 
  Create(Row,Col);
  for(int i = 1; i <= M; i++)
    for(int j = 1; j <= N ; j++)
       A[i][j]=V[(i-1)*Col+(j-1)];
  return;
}

// 複製建構函數的定義
template <class T>
Matrix<T>::Matrix(Matrix<T>& OldM)
{ 
  Create(OldM.M, OldM.N);
  for(int i = 1; i <= M; i++)
    for(int j = 1; j <= N ; j++)
       A[i][j]=OldM.A[i][j];
  return;
}

// 解構函數的定義
template <class T>
Matrix<T>::~Matrix()
{ 
  delete [] A[0];
  delete [] A;
}

// 定義指派運算子 operator = ()
template <class T>
Matrix<T>
Matrix<T>::operator=(const Matrix<T>& M2)
{ 
  if ((M!=M2.M)||(N!=M2.N))
    Create(M2.M, M2.N);
  for(int i = 1; i <= M; i++)
    for(int j = 1; j <= N ; j++)
      A[i][j]=M2.A[i][j];
  return *this;
}

// 定義加法運算子 operator + ()
template <class T>
Matrix<T>
Matrix<T>::operator+(const Matrix<T>& M2)
{ 
  Check((M!=M2.M)||(N!=M2.N),
    "矩陣加法運算錯誤, 大小不相同!");
  Matrix<T> temp(M,N);
  for(int i = 1; i <= M; i++)
    for(int j = 1; j <= N ; j++)
           temp.A[i][j]=A[i][j]+M2.A[i][j];
  return temp;
}

// 定義乘法運算子  operator * ()
template <class T>
Matrix<T>
Matrix<T>::operator*(const Matrix<T>& M2)
{ 
  Check(N!=M2.M,
    "矩陣乘法運算錯誤, 大小不配!");
  Matrix<T> temp(M,M2.N);
  for(int i = 1; i <= M; i++)
    for(int j = 1; j <= M2.N ; j++)
      {	temp.A[i][j]=0.0;
        for(int k = 1; k <= N ; k++)
           temp.A[i][j]+=A[i][k]*M2.A[k][j];
      }
  return temp;
}

// 定義成員函數 Display()
template <class T>
void Matrix<T>::Display()
{   
    cout << setiosflags(ios::right)
         << setiosflags(ios::fixed)
         << setiosflags(ios::showpoint)
         << setprecision(4);
    for (int i = 1; i <= M; i++)
    { for(int j = 1; j <= N ; j++)
        cout << setw(10)
             << A[i][j] << " " ;
      cout << endl;
    }
    return;
}

// 定義成員函數 PickCol()
template <class T>
Vector<T> Matrix<T>::PickCol(int I)
{ 
  Vector<T> TempV(M);
  for (int i=1; i<= M; i++)
       TempV[i]= A[i][I];
  return TempV;
}

// 定義成員函數 SetCol()
template <class T>
void Matrix<T>::SetCol(int j, Vector<T>& V1)
{ 
  for (int i=1; i<= M; i++)
     A[i][j]= V1[i];
  return;
}

#endif