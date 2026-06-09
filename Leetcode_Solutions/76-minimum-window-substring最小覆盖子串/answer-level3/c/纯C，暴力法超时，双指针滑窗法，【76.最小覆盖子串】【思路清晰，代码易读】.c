### 解题思路
方法二：双指针滑窗法
思路
1,iLeft,iRight 两个指针进行滑窗处理，
2,当窗口不满足子串时则 iRight++ 增大窗口直到窗口满足子串
3,当窗口满足子串则 iLeft++ 减小窗口，找到当前最小子串，直到破坏窗口跳到步骤2
4,窗口在不断右移的过程中，不断增大减小，直到整个字符串结束，找到过程中最小子串

问题：如何判断窗口满足要求，是这类双指针滑窗法的关键，好的方法就更快

方法：
1,对字符串 T 进行处理，使用数组标记字符串T中每个字符出现的次数 tFlag[52], 并用 iNeedNum 记录T中字符出现的个数
2,使用 tFlagTmp[52] 记录窗口中目标字符(T中包含的)的次数，并用 iMatchNum 记录过程中出现目标字符的个数
3,当 tFlagTmp[n] >= tFlag[n] 时 iMatchNum++  当 tFlagTmp[n] < tFlag[n] 时 iMatchNum-- 
4,当窗口中 iMatchNum == iNeedNum 时说明窗口满足要求

### 代码

```c
//方法二：双指针滑窗法
//思路
//1,iLeft,iRight 两个指针进行滑窗处理，
//2,当窗口不满足子串时则 iRight++ 增大窗口直到窗口满足子串
//3,当窗口满足子串则 iLeft++ 减小窗口，找到当前最小子串，直到破坏窗口跳到步骤2
//4,窗口在不断右移的过程中，不断增大减小，直到整个字符串结束，找到过程中最小子串

//问题：
//1,如何判断窗口满足要求，是这类双指针滑窗法的关键，好的方法就更快
//2,对字符串 T 进行处理，使用数组标记字符串T中每个字符出现的次数 tFlag[52], 并用 iNeedNum 记录T中字符出现的个数
//3,使用 tFlagTmp[52] 记录窗口中目标字符(T中包含的)的次数，并用 iMatchNum 记录过程中出现目标字符的个数
//4,当 tFlagTmp[n] >= tFlag[n] 时 iMatchNum++  当 tFlagTmp[n] < tFlag[n] 时 iMatchNum-- 
//5,当窗口中 iMatchNum == iNeedNum 时说明窗口满足要求

#define     ALPHANUM    26
int getAlphIndex(char alpha)
{
    int     iIndex  = 0;

    if ((alpha >= 'a') && (alpha <= 'z'))
    {
        iIndex = alpha - 'a';
    }
    else if ((alpha >= 'A') && (alpha <= 'Z'))
    {
        iIndex = alpha - 'A' + ALPHANUM;
    }
    else 
    {
        iIndex = ALPHANUM * 2;
    }
    return iIndex;
}

char * minWindow(char * s, char * t){
    int     i           = 0;
    int     iLeft       = 0;
    int     iRight      = 0;
    int     iLenS       = strlen(s);
    int     iLenT       = strlen(t);
    int     iMinLen     = iLenS;
    int     iMinPos     = 0;
    int     iTmpIndex   = 0;
    int     iNeedNum    = 0;
    int     iMatchNum   = 0;
    bool    bExit       = false;
    char*   pRet        = NULL;
    int     tFlag[(ALPHANUM * 2 + 1)];
    int     tFlagTmp[(ALPHANUM * 2 + 1)];

    memset(tFlag, 0x00, sizeof(int) * (ALPHANUM * 2 + 1));
    memset(tFlagTmp, 0x00, sizeof(int) * (ALPHANUM * 2 + 1));

    pRet = (char*)malloc(sizeof(char) * (iLenS + 1));
    memset(&pRet[0], 0x00, sizeof(char) * (iLenS + 1));

    if ((NULL == s) || (NULL == t)) return pRet;
    if (iLenS < iLenT) return pRet;

    //1,初始化字符串T的标记数组
    for (i = 0; i < iLenT; i++)
    {
        iTmpIndex = getAlphIndex(t[i]);
        if (tFlag[iTmpIndex] == 0) iNeedNum += 1;
        tFlag[iTmpIndex] += 1;
    }

    //2,定位 iLeft 和 iRight 初始位置
    for (i = 0; i < iLenS; i++)
    {
        iTmpIndex = getAlphIndex(s[i]);
        if (tFlag[iTmpIndex] != 0)
        {
            iLeft = i;
            iRight = i;
            tFlagTmp[iTmpIndex] += 1;
            if (tFlagTmp[iTmpIndex] == tFlag[iTmpIndex]) iMatchNum += 1;
            break;
        }
    }

    //3,双指针
    while (iRight < iLenS)
    {
        if (iMatchNum != iNeedNum)
        {
            iRight += 1;
            //4,窗口不满足条件，则 iRight 右移到下一个是字符串T中的元素，并重新判断
            for (; iRight < iLenS; iRight++)
            {
                iTmpIndex = getAlphIndex(s[iRight]);
                if (tFlag[iTmpIndex] != 0)
                {
                    break;
                }
            }
            if (iRight >= iLenS) break;
            tFlagTmp[iTmpIndex] += 1;
            if (tFlagTmp[iTmpIndex] == tFlag[iTmpIndex]) iMatchNum += 1;
        }
        else
        {
            bExit = true;
            //5,窗口满足条件，判断最小子串
            if (iRight - iLeft + 1 < iMinLen)
            {
                iMinLen = iRight - iLeft + 1;
                iMinPos = iLeft;
            }

            //6,窗口满足条件，则 iLeft 右移到下一个是字符串T中的元素，并重新判断
            iTmpIndex = getAlphIndex(s[iLeft]);
            if (tFlag[iTmpIndex] != 0)
            {
                tFlagTmp[iTmpIndex] -= 1;
                if (tFlagTmp[iTmpIndex] < tFlag[iTmpIndex]) iMatchNum -= 1;
                iLeft += 1;
            }

            for (; iLeft < iLenS - iLenT; iLeft++)
            {
                iTmpIndex = getAlphIndex(s[iLeft]);
                if (tFlag[iTmpIndex] != 0)
                {
                    break;
                }
            }
            if (iLeft > iLenS - iLenT) break;
        }
    }

    //7,输出
    if (bExit)
    {
        memcpy(&pRet[0], &s[iMinPos], iMinLen);
    }
    return pRet;
}



/*
//方法一：暴力法
#define     ALPHANUM    26
int getAlphIndex(char alpha)
{
    int     iIndex  = 0;

    if ((alpha >= 'a') && (alpha <= 'z'))
    {
        iIndex = alpha - 'a';
    }
    else if ((alpha >= 'A') && (alpha <= 'Z'))
    {
        iIndex = alpha - 'A' + ALPHANUM;
    }
    else 
    {
        iIndex = ALPHANUM * 2;
    }
    return iIndex;
}

char * minWindow(char * s, char * t){
    int     i           = 0;
    int     j           = 0;
    int     iLenS       = strlen(s);
    int     iLenT       = strlen(t);
    int     iTmpLen     = 0;
    int     iMinLen     = iLenS;
    int     iMinPos     = 0;
    int     iTmpIndex   = 0;
    bool    bExit       = false;
    char*   pRet        = NULL;
    char    tFlag[(ALPHANUM * 2 + 1)];
    char    tFlagTmp[(ALPHANUM * 2 + 1)];
    char    tFlagEmpty[(ALPHANUM * 2 + 1)];

    memset(tFlag, 0x00, sizeof(char) * (ALPHANUM * 2 + 1));
    memset(tFlagTmp, 0x00, sizeof(char) * (ALPHANUM * 2 + 1));
    memset(tFlagEmpty, 0x00, sizeof(char) * (ALPHANUM * 2 + 1));

    pRet = (char*)malloc(sizeof(char) * (iLenS + 1));
    memset(&pRet[0], 0x00, sizeof(char) * (iLenS + 1));

    if ((NULL == s) || (NULL == t)) return pRet;
    if (iLenS < iLenT) return pRet;

    //1,初始化字符串T的标记数组
    for (i = 0; i < iLenT; i++)
    {
        iTmpIndex = getAlphIndex(t[i]);
        tFlag[iTmpIndex] += 1;
    }
    
    //2,遍历字符串 S ，查找最小子串
    for (i = 0; i <= iLenS - iLenT; i++)
    {
        iTmpIndex = getAlphIndex(s[i]);
        if (tFlag[iTmpIndex] == 0) continue;

        iTmpLen = 0;
        memcpy(&tFlagTmp[0], &tFlag[0], sizeof(char) * (ALPHANUM * 2 + 1));

        for (j = i; j < iLenS; j++)
        {
            iTmpIndex = getAlphIndex(s[j]);
            if (tFlagTmp[iTmpIndex] == 0) continue;
            tFlagTmp[iTmpIndex] -= 1;
            if (0 == memcmp(&tFlagTmp[0], &tFlagEmpty[0], sizeof(char) * (ALPHANUM * 2 + 1)))
            {
                bExit = true;
                iTmpLen = j - i + 1;
                break;
            }
        }

        if (j >= iLenS)
        {
            break;
        }

        if (iTmpLen < iMinLen)
        {
            iMinLen = iTmpLen;
            iMinPos = i;
        }
    }

    if (bExit)
    {
        memcpy(&pRet[0], &s[iMinPos], iMinLen);
    }

    return pRet;
}
*/
```