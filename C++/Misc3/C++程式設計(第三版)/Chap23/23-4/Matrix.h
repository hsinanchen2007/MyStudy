// Matrix.h

#ifndef Matrix_H
#define Matrix_H

#include <iostream>
#include <iomanip>
using namespace std;

// == �ŧi Matrix �˪����O ===============
template <class T>
class Matrix
{ 
  private:
    int M, N;
    T** A;
    void Create(int, int);
  public:
    // �ŧi�غc���
    Matrix(int, int);
    Matrix(int, int, const T*);
    // �ŧi�ƻs�غc���
    Matrix(Matrix<T>&);
    // �ŧi�Ѻc���
    ~Matrix();
    //operator
    // �ŧi�����B��l operator = ()
    Matrix<T> operator=(const Matrix<T>&);
    // �ŧi�[�k�B��l operator + ()
    Matrix<T> operator+(const Matrix<T>&);
    // �ŧi���k�B��l operator * ()
    Matrix<T> operator*(const Matrix<T>&);
    // �ŧi���޹B��l operator [] ()
    T* operator[](int i){return A[i];}
    // �ŧi������� SetCol()
    void SetCol(int, Vector<T>&);
    // �ŧi������� PickCol()
    Vector<T> PickCol(int);
    // �ŧi������� Display()
    void Display();
};

// =======  ������ƪ��w�q  ================
// ��� Create() ���w�q
template <class T>
void Matrix<T>::Create(int Row, int Col)
{
  Check((Row<1)||(Col<1),
    "�x�}�غc���~, ��C�j�p���ର�t��!");
  M = Row;
  N = Col;
  A = new T* [M+1];
  A[0]= new T[M*N+1];
  A[1]= A[0];
  for(int i=2; i<= M; i++)
     A[i]=A[i-1]+N;
}

// �غc��ƪ��w�q
template <class T>
Matrix<T>::Matrix(int Row, int Col)
   { Create(Row,Col);  return;}


// �غc��ƪ��w�q (�q�@���}�C�إߤG���}�C)
template <class T>
Matrix<T>::Matrix(int Row, int Col, const T* V)
{ 
  Create(Row,Col);
  for(int i = 1; i <= M; i++)
    for(int j = 1; j <= N ; j++)
       A[i][j]=V[(i-1)*Col+(j-1)];
  return;
}

// �ƻs�غc��ƪ��w�q
template <class T>
Matrix<T>::Matrix(Matrix<T>& OldM)
{ 
  Create(OldM.M, OldM.N);
  for(int i = 1; i <= M; i++)
    for(int j = 1; j <= N ; j++)
       A[i][j]=OldM.A[i][j];
  return;
}

// �Ѻc��ƪ��w�q
template <class T>
Matrix<T>::~Matrix()
{ 
  delete [] A[0];
  delete [] A;
}

// �w�q�����B��l operator = ()
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

// �w�q�[�k�B��l operator + ()
template <class T>
Matrix<T>
Matrix<T>::operator+(const Matrix<T>& M2)
{ 
  Check((M!=M2.M)||(N!=M2.N),
    "�x�}�[�k�B����~, �j�p���ۦP!");
  Matrix<T> temp(M,N);
  for(int i = 1; i <= M; i++)
    for(int j = 1; j <= N ; j++)
           temp.A[i][j]=A[i][j]+M2.A[i][j];
  return temp;
}

// �w�q���k�B��l  operator * ()
template <class T>
Matrix<T>
Matrix<T>::operator*(const Matrix<T>& M2)
{ 
  Check(N!=M2.M,
    "�x�}���k�B����~, �j�p���t!");
  Matrix<T> temp(M,M2.N);
  for(int i = 1; i <= M; i++)
    for(int j = 1; j <= M2.N ; j++)
      {	temp.A[i][j]=0.0;
        for(int k = 1; k <= N ; k++)
           temp.A[i][j]+=A[i][k]*M2.A[k][j];
      }
  return temp;
}

// �w�q������� Display()
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

// �w�q������� PickCol()
template <class T>
Vector<T> Matrix<T>::PickCol(int I)
{ 
  Vector<T> TempV(M);
  for (int i=1; i<= M; i++)
       TempV[i]= A[i][I];
  return TempV;
}

// �w�q������� SetCol()
template <class T>
void Matrix<T>::SetCol(int j, Vector<T>& V1)
{ 
  for (int i=1; i<= M; i++)
     A[i][j]= V1[i];
  return;
}

#endif