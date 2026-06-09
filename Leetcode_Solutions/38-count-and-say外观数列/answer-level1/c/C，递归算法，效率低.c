### 解题思路
递归算法：
    1,结束条件 n==1
    2,f(n) = f(n - 1)
    3,根据 n-1 结果得出 n 的结果
### 代码

```c

//递归算法：
//1,结束条件 n==1
//2,f(n) = f(n - 1)
//3,根据 n-1 结果得出 n 的结果
int recursionCount(char* pRet, int n){
    int     i       = 0;
    int     j       = 0;
    int     iNum    = 0;
    int     iRet    = 0;
    char*   pTmp    = NULL;

    if (1 == n)
    {
        pRet[n - 1] = '1';
        iRet = 1;
        return iRet;
    }

    iNum = recursionCount(pRet, n - 1);

    pTmp = (char*)malloc(sizeof(char) * (iNum * 2));
    memcpy(pTmp, pRet, iNum);
    memset(pRet, 0x00, iNum);
    j = 0;

    for (i = 0; i <= iNum - 1; i++)
    {
        if ((iNum >= 3) && (pTmp[i] == pTmp[i + 1]) && (pTmp[i + 1] == pTmp[i + 2]))
        {
            pRet[j] = '3';
            pRet[j + 1] = pTmp[i];
            i += 2;
            j += 2;
            iRet += 2;
        }
        else if ((iNum >= 2) && (pTmp[i] == pTmp[i + 1]))
        {
            pRet[j] = '2';
            pRet[j + 1] = pTmp[i];
            i += 1;
            j += 2;
            iRet += 2;
        }
        else
        {
            pRet[j] = '1';
            pRet[j + 1] = pTmp[i];
            j += 2;
            iRet += 2;
        }
    }

    free(pTmp);
    return iRet;
}

char * countAndSay(int n){
    char*       pRet        = NULL;
    long int    arrySize    = 0;

    arrySize = 1 << (n - 1);

    pRet = (char *)malloc(sizeof(char) * (arrySize + 1));
    memset(pRet, 0x00, sizeof(char) * (arrySize + 1));

    recursionCount(pRet, n);

//    printf("%ld\n", arrySize);

    return pRet;
}
```