### 解题思路
方法一：循环乘法+特殊处理
1, 0的0次幂没有意义，其他任何不为0的数的0次幂都为1
2, 0的除0以外任何数的次幂都为0
3, 1的任何次幂都为1
4, -1的偶次幂为1，奇次幂为-1
5, 将n转换为负数，然后循环避免最大负数不能转换为正数的问题 int值范围 -2147483648~2147483647
6, 乘积过程中如果结果已经等于0，则直接结束，负N次幂的处理
7, 负N次幂的结果处理
8, 浮点数 double 的绝对值函数 fabs，整形用 abs

### 代码

```c
//方法一：循环乘法+特殊处理
//1, 0的0次幂没有意义，其他任何不为0的数的0次幂都为1
//2, 0的除0以外任何数的次幂都为0
//3, 1的任何次幂都为1
//4, -1的偶次幂为1，奇次幂为-1
//5, 将n转换为负数，然后循环避免最大负数不能转换为正数的问题 int值范围 -2147483648~2147483647
//6, 乘积过程中如果结果已经等于0，则直接结束，负N次幂的处理
//7, 负N次幂的结果处理
//8, 浮点数 double 的绝对值函数 fabs，整形用 abs
#define     SBA(a)      ((a > 0) ? (0 - (a)) : (a))

double myPow(double x, int n){
    int     i       = 0;
    int     iAbs_n  = n;
    double  dTmp    = 1.0;
    double  dRet    = 1.0;
//-2147483648~2147483647
    if (n == 0) return dRet;
    if (fabs(x - 0.0) < 0.000001) return x; 
    if (fabs(x - 1.0) < 0.000001) return x;
    if (fabs(x + 1.0) < 0.000001)
    {
        if (0 == (n % 2))
        {
            return dRet;
        }
        else
        {
            return x;
        }
    }

    if (n > 0)
    {
        iAbs_n = 0 - n;
    }

    for (i = 0; i > iAbs_n; i--)
    {
//        printf("[i=%d][Ret=%.2lf]\n", i, dRet);
        dTmp *= x;

        if (n < 0)
        {
            dRet =  ((double)1) / dTmp;
            if (fabs(dRet - 0.0) < 0.000001) return dRet;
        }
        else
        {
            dRet = dTmp;
             if (fabs(dRet - 0.0) < 0.000001) return dRet;
        }
    }

    if (n < 0)
    {
        dRet =  ((double)1) / dTmp;
    }
    else
    {
        dRet = dTmp;
    }

    return dRet;
}
```