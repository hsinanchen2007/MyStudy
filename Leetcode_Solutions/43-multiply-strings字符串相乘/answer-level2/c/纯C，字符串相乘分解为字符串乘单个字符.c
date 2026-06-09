### 解题思路
方法一：
1,固定num1,遍历num2,用num2中每一个元素和num1做乘法
2,申请一个结果空间，一个辅助空间,pTmp保存每次的中间结果
3,将中间结果累加到 pRet 结果中,注意整个过程中为了操作方便，pTmp 和 pRet 中字符都是倒序的
4,将最终结果倒序，返回结果，释放空间

### 代码

```c
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
```