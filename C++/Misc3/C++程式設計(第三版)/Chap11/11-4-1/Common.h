// Common.h
// --------------------------------------
// Copyright (c) Yau-Zen Chang (2002.01-) 
// All Rights Reserved.
// ���{�����v�ݩ� �iģ��
// �ϥήɥ����n��.
// --------------------------------------
#ifdef Common_h
#else
#define Common_h
#include <iostream>
using namespace std;
// -- �������O ---------------------------
#define MAX(x,y) ((x) > (y) ?  (x) : (y))
#define PRODUCT(x,y) ((x) * (y))
#define Merge(x, y) x##y 
#define ShowValue(x)                                    \
  {                                                                    \
    cerr << #x << " ���ȬO: " << x << endl;   \
    cerr << "�� Enter ���~��." << endl;          \
    cin.get();                                                       \
  } 	
#endif