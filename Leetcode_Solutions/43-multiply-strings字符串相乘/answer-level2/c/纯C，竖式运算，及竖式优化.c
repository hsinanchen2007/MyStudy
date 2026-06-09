### 解题思路
方法一：
1,固定num1,遍历num2,用num2中每一个元素和num1做乘法
2,申请一个结果空间，一个辅助空间,pTmp保存每次的中间结果
3,将中间结果累加到 pRet 结果中,注意整个过程中为了操作方便，pTmp 和 pRet 中字符都是倒序的

方法二：竖式优化
    利用 num1[i] * num2[j] 的结果在 pRet[i + j] 和 pRet[i + j + 1] 位置的特性优化算法

### 代码

```c
//函数三：字符串倒序
void reverseOrderRet(char* pRet){
    int     i       = 0;
    char    cTmp    = 0;
    int     iLen    = strlen(pRet);

    for (i = 0; i < (iLen + 1) / 2; i++)
    {
        cTmp = pRet[i];
        pRet[i] = pRet[iLen - i - 1];
        pRet[iLen - i - 1] = cTmp;
    }
    return;
}

//方法二：竖式优化
//利用 num1[i] * num2[j] 的结果在 pRet[i + j] 和 pRet[i + j + 1] 位置的特性优化算法
char * multiply(char * num1, char * num2){
    int     i               = 0;
    int     j               = 0;
    int     iNumLen_1       = strlen(num1);
    int     iNumLen_2       = strlen(num2);
    char*   pRet            = NULL;
    int     iTmp            = 0;
    int     iSingle         = 0;
    int     iTen            = 0;
    int     iRetLen         = 0;

    pRet = (char*)malloc(sizeof(char) * 250);
    memset(pRet, 0x00, sizeof(char) * 250);

    if ((NULL == num1) || (NULL == num2)) return NULL;
    if ((num1[0] == '0') || (num2[0] == '0')) 
    {
        pRet[0] = '0';
        return pRet; 
    }

    //1,为了方便计算将 num1 和 num2 反转
    reverseOrderRet(num1);
    reverseOrderRet(num2);

    //2,循环计算 num1[i] * num2[j] 并将结果保存到对应位置
    for (i = 0; i < iNumLen_1; i++)
    {
        for (j = 0; j < iNumLen_2; j++)
        {
            iTmp = (num1[i] - '0') * (num2[j] - '0');
            iSingle = iTmp % 10;
            iTen = iTmp / 10;
            pRet[i + j] += iSingle;
            iRetLen = i + j + 1;

            if (iTen > 0)
            {
                pRet[i + j + 1] += iTen;
                iRetLen = i + j + 2;
            }

            if (pRet[i + j] > 9)
            {
                pRet[i + j] = (pRet[i + j] - 0) % 10;
                pRet[i + j + 1] += 1;
                iRetLen = i + j + 2;
            }

            if (pRet[i + j + 1] > 9)
            {
                pRet[i + j + 1] = pRet[i + j + 1] % 10;
                pRet[i + j + 2] += 1;
                iRetLen = i + j + 3;
            }
        }
    }

    //3，将 pRet 中数字转换成字符
    for (i = 0; i < iRetLen; i++)
    {
        pRet[i] += '0';
    }

    //4,反转 pRet 得到结果
    reverseOrderRet(pRet);

    return pRet;
}

/*
//函数一：单个字符 乘 字符串,结果倒序保存
int multiply_single(char* num, char single, char* pTmp){
    int     i               = 0;
    int     iSingle         = 0;
    int     iTen            = 0;
    int     iTmp            = 0;
    int     iNumLen         = strlen(num);
    int     index           = 0;

    for (i = iNumLen - 1; i >= 0; i--)
    {
        iTmp = (num[i] - '0') * (single - '0');
        iSingle = iTmp % 10;
        if (iSingle + iTen >= 10)
        {
            pTmp[index] = iSingle + iTen - 10 + '0';
            iTen = iTmp / 10 + 1;
        }
        else
        {
            pTmp[index] = iSingle + iTen + '0';
            iTen = iTmp / 10;
        }
        index += 1;
    }

    if (iTen > 0)
    {
        pTmp[index] = iTen + '0';
        index += 1;
    }
    return index;
}

//函数二：字符串相加，pRet * 10 然后加上 pTmp ,倒序操作
int addTmpToRet(char* pRet, char* pTmp){
    int     i           = 0;
    int     j           = 0;
    int     iRetLen     = strlen(pRet);
    int     iTmpLen     = strlen(pTmp);
    int     iTmpSum     = 0;
    int     iSingle     = 0;
    int     iTen        = 0;

    for (i = 0, j = 1; i < iRetLen; i++, j++)
    {
        if ((pTmp[j] >= '0') && (pTmp[j] <= '9'))
        {
            iTmpSum = (pRet[i] - '0') + (pTmp[j] - '0') + iTen;
        }
        else
        {
            iTmpSum = (pRet[i] - '0') + iTen;
        }

        iSingle = iTmpSum % 10;
        iTen = iTmpSum / 10;
        pTmp[j] = iSingle + '0';
    }

    if (iTen > 0)
    {
        pTmp[j] = iTen + '0';
        j += 1;
    }

    memcpy(pRet, pTmp, sizeof(char) * j);
    return j;
}

//函数三：字符串倒序
void reverseOrderRet(char* pRet){
    int     i       = 0;
    char    cTmp    = 0;
    int     iLen    = strlen(pRet);

    for (i = 0; i < (iLen + 1) / 2; i++)
    {
        cTmp = pRet[i];
        pRet[i] = pRet[iLen - i - 1];
        pRet[iLen - i - 1] = cTmp;
    }
    return;
}

//方法一：
//1,固定num1,遍历num2,用num2中每一个元素和num1做乘法
//2,申请一个结果空间，一个辅助空间,pTmp保存每次的中间结果
//3,将中间结果累加到 pRet 结果中,注意整个过程中为了操作方便，pTmp 和 pRet 中字符都是倒序的
//4,将最终结果倒序，返回结果，释放空间
char * multiply(char * num1, char * num2){
    int     j               = 0;
    int     iTmpLen         = 0;
    int     iNumLen_2       = strlen(num2);
    char*   pTmp            = NULL;
    char*   pRet            = NULL;

    //1，初始化
    pTmp = (char*)malloc(sizeof(char) * 250);
    memset(pTmp, 0x00, sizeof(char) * 250);
    pRet = (char*)malloc(sizeof(char) * 250);
    memset(pRet, 0x00, sizeof(char) * 250);

    if ((NULL == num1) || (NULL == num2)) return NULL;
    if ((num1[0] == '0') || (num2[0] == '0')) 
    {
        pRet[0] = '0';
        return pRet; 
    }

    for (j = 0; j < iNumLen_2; j++)
    {
        memset(pTmp, 0x00, sizeof(char) * 250);
        //2,计算 num1 * num2[j]
        iTmpLen = multiply_single(num1, num2[j], pTmp);

//        printf("[1] %s, len=%d\n", pTmp, iTmpLen);

        //3,将中间结果 pTmp 累加到 pRet 中
        if (0 == j)
        {
            memcpy(pRet, pTmp, sizeof(char) * iTmpLen);
        }
        else
        {
            iTmpLen = addTmpToRet(pRet, pTmp);
        }

//        printf("[2]len=%d %s\n", iTmpLen, pRet);
    }

    //4,倒序结果，释放空间
    reverseOrderRet(pRet);
    free(pTmp);

    return pRet;
}
*/
```