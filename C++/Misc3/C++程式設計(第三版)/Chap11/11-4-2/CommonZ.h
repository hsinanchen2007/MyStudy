// Common.h
// --------------------------------------
// Copyright (c) Yau-Zen Chang (2002.01-) 
// All Rights Reserved.
// ����ʽ��Ȩ���� ��ҫ��
// ʹ��ʱ��������.
// --------------------------------------
#ifdef Common_h
#else
#define Common_h
#include <iomanip>
#include <iostream>
#include <conio>
#include <stdio>
using std::cerr;
using std::cout;
using std::endl;
// -- �޼�ָ�� ---------------------------
#define MAX(x,y) ((x) > (y) ?  (x) : (y))
#define PRODUCT(x,y) ((x) * (y))
#define Merge(x, y) x##y 
#define ShowValue(x)                        \
  {                                         \
    cerr << #x << " ��ֵ��: " << x << endl; \
    cerr << "�� Enter ������." << endl;     \
    getchar();                              \
  } 	
#endif