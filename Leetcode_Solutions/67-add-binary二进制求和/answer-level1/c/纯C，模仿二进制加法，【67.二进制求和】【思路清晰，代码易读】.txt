### 解题思路
方法一：模拟二进制加法

### 代码

```c
//方法一：模拟二进制加法
#define     MAX(a, b)   ((a) > (b) ? (a) : (b))
char * addBinary(char * a, char * b){
    int     i       = 0;
    int     iLenA   = strlen(a);
    int     iLenB   = strlen(b);
    int     iLenMax = MAX(iLenA, iLenB);
    int     iTmpA   = 0;
    int     iTmpB   = 0;

    char*   pRet    = NULL;
    pRet = (char*)malloc(sizeof(char) * (iLenMax + 2));
    memset(pRet, 0x00, sizeof(char) * (iLenMax + 2));

    for (i = 0; i < iLenMax; i++)
    {
        if (iLenA - i > 0)
        {
            iTmpA = a[iLenA - i - 1] - '0';
        }
        else
        {
            iTmpA = 0;
        }

        if (iLenB - i > 0)
        {
            iTmpB = b[iLenB - i - 1] - '0';
        }
        else
        {
            iTmpB = 0;
        }

        pRet[iLenMax - i] += iTmpA + iTmpB;
        if (pRet[iLenMax - i] >= 2)
        {
            pRet[iLenMax - i] -= 2;
            pRet[iLenMax - i - 1] = 1;
        }
        pRet[iLenMax - i] += '0';
    }

    if (pRet[0] == 0)
    {
        return &pRet[1];
    }
    else
    {
        pRet[0] += '0';
        return &pRet[0];
    }
}
```