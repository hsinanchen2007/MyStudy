### 解题思路
方法一：单纯使用减法，及特殊处理，时间超时
方法二：除数左移增倍，减少被除数减除数的次数
    1，中心思想：被除数-除数 前，通过左移扩大除数的倍数，找出最大除数，每次增加的倍数之和即为结果
    2，C语言中负数不支持左移操作，所以无法完全转换成负数操作，如果能转换成负数操作则溢出问题好解决
    3，特殊处理溢出问题，除数和被除数都需要考虑为 0x80000000 的情况
    4，除数左移，需要判断是否超过 int 的最大值，超过也会报错
    5，

### 代码

```c

//方法二：除数左移增加倍数，以减少循环次数，C语言负数不能左移，左移只能做正数判断
int divide(int dividend, int divisor){
    int     iRet    = 0;
    int     iTmpRet = 1;
    int     iFlag   = 1;
    int     iTmp    = 0;

    int     iDividend   = dividend;
    int     iDivisor    = divisor;

    //1,被除数特殊判断，避免后面转换成正数溢出
    if (iDivisor == 0x80000000)
    {
        if (iDividend == 0x80000000)
        {
            iRet = 1;
            return iRet;
        }
        else
        {
            iRet = 0;
            return iRet;
        }
    }

    //2,除数特殊处理，避免后面计算出现溢出
    if (iDividend == 0x80000000)
    {
        if (iDivisor == -1)
        {
            iRet = 0x7fffffff;
            return iRet;
        }
        if (iDivisor == 1)
        {
            return iDividend;
        }
    }

    if ((dividend & 0x80000000) ^ (divisor & 0x80000000)) iFlag = -1;
    if (divisor > 0) divisor = 0 - divisor;             //除数转换成负数，用于做比较
    if (iDividend > 0) iDividend = 0 - iDividend;       //被除数转换成负数，避免溢出

//    printf("(%d, %d), (%d, %d)\n", dividend, divisor, iDividend, iDivisor);

    while (iDividend <= divisor)
    {
        iTmpRet = 1;

        iDivisor = divisor;
        if (iDivisor < 0) iDivisor = 0 - iDivisor;      //除数转换成正数，方便左移， 最大值已处理，此处不会溢出

        if (iDivisor <= (0x7ffffff >> 1))
        {
            while (iDividend < (0 - (iDivisor << 1)))
            {
                // 左移除数，增加除数的倍数，找到仅小于被除数的最大值
                if (iDivisor >= (0x7ffffff >> 1)) break;
                iDivisor = iDivisor << 1;       //增加除数的倍数
                iTmpRet = iTmpRet << 1;         //记录每一次增加的倍数
            }
        }

        iDividend = iDividend + iDivisor;   //被除数减去最大的除数，此处为加法其实为减法
        iRet += iTmpRet;                    //计算结果累加，结果为正数

//        printf("(%d, %d), (%d, %d), %d\n", dividend, divisor, iDividend, iDivisor, iRet);
    }

    //调整结果的符号
    if (iFlag == -1)
    {
        iRet = 0 - iRet;
    }
    return iRet;
}

/*
//方法一：完全减法暴力破解，效率低下，超时
int divide(int dividend, int divisor){
    int     iRet    = 0;
    int     iFlag   = 0;
    int     isSpe   = 0;

    int     iDividend   = dividend;
    int     iDivisor    = divisor;

    if ((dividend & 0x80000000) ^ (divisor & 0x80000000))
    {
        //被除数和除数符号位不相同，则为负值
        iFlag = -1;
    }
    else
    {
        //被除数和除数符号位不相同，则为正值
        iFlag = 1;
    }

//    printf("D1=%08x, D2=%08x, iFlag=%d\n", dividend, divisor, iFlag);


    if (iDividend < 0)
    {
        if (iDividend == 0x80000000)
        {
            if (iDivisor == -1)
            {
                iDividend = 0x7fffffff;
                return iDividend;
            }
            else if (iDivisor == 1)
            {
                return iDividend;
            }
            else if (iDivisor == 0x80000000)
            {
                iRet = 1;
                return iRet;
            }
            else
            {
                isSpe = 1;
                iDividend = 0x7fffffff;
            }
        }
        else
        {
            iDividend = 0 - iDividend;
        }
    }

    if (iDivisor < 0)
    {
        if (iDivisor == 0x80000000)
        {
            if (iDividend == 0x80000000)
            {
                iRet = 1;
            }
            else
            {
                iRet = 0;
            }
            return iRet;
        }
        else
        {
            iDivisor = 0 - iDivisor;
        }
    }

    if (1 == iDivisor)
    {
        iRet = iDividend;
    }
    else
    {
        while (iDividend >= iDivisor)
        {
            iRet += 1;
            iDividend -= iDivisor;

            if (isSpe == 1)
            {
                iDividend += 1;
                isSpe = 0;
            }
        }
    }

    if (-1 == iFlag)
    {
        iRet = 0 - iRet;
    }

    return iRet;
}
*/
```