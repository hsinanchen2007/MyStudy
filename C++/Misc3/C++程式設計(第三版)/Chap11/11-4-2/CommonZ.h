// Common.h
// --------------------------------------
// Copyright (c) Yau-Zen Chang (2002.01-) 
// All Rights Reserved.
// 本程式版权属于 张耀仁
// 使用时必需声明.
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
// -- 巨集指令 ---------------------------
#define MAX(x,y) ((x) > (y) ?  (x) : (y))
#define PRODUCT(x,y) ((x) * (y))
#define Merge(x, y) x##y 
#define ShowValue(x)                        \
  {                                         \
    cerr << #x << " 的值是: " << x << endl; \
    cerr << "按 Enter 键继续." << endl;     \
    getchar();                              \
  } 	
#endif