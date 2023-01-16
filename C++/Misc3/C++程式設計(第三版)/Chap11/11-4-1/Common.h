// Common.h
// --------------------------------------
// Copyright (c) Yau-Zen Chang (2002.01-) 
// All Rights Reserved.
// 本程式版權屬於 張耀仁
// 使用時必需聲明.
// --------------------------------------
#ifdef Common_h
#else
#define Common_h
#include <iostream>
using namespace std;
// -- 巨集指令 ---------------------------
#define MAX(x,y) ((x) > (y) ?  (x) : (y))
#define PRODUCT(x,y) ((x) * (y))
#define Merge(x, y) x##y 
#define ShowValue(x)                                    \
  {                                                                    \
    cerr << #x << " 的值是: " << x << endl;   \
    cerr << "按 Enter 鍵繼續." << endl;          \
    cin.get();                                                       \
  } 	
#endif