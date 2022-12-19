### 解题思路
方法一：暴力破解，时间超时
方法二：滑窗法，
    1，遍历字符串一遍，进行窗口滑动
    2，依次将窗口中的单词做匹配
    3，检查匹配结果

注意：在使用 strncmp 之前先增加判断第一个字符是否相等，会大大提高运行效率
但是自己写的循环比较字符串是否相等，效率又不如系统函数 strncmp
### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

//在单词数组 words 中匹配窗口中的单词，匹配成功，将对应的结果pRet[i] = 1
bool matchWords(char* pWindow, char** words, int wordsSize, int* pRet){
    bool    bRet    = false;
    int     i       = 0;
    int     iWlen   = strlen(words[0]);

    for (i = 0; i < wordsSize; i++)
    {
//        printf("[i=%d][pwin=%s][word=%s][pRet=%d][wSize=%d]\n", i, pWindow, words[i], pRet[i], wordsSize);
        if (pRet[i] == 1) continue;
        if ((pWindow[0] == words[i][0]) && (0 == strncmp(pWindow, words[i], iWlen)))
        {
            bRet = true;
            pRet[i] = 1;
            break;
        }
    }
    return bRet;
}

//检查单词匹配结果是否都匹配上
bool checkRetFlag(int* pRet, int wordsSize){
    int     i       = 0;
    bool    bRet    = true;

    for (i = 0; i < wordsSize; i++)
    {
//        printf("[i=%d][pRet=%d]\n", i, pRet[i]);
        if (1 != pRet[i])
        {
            bRet = false;
            break;
        }
    }

    return bRet;
}   

//方法二：滑动窗口
int* findSubstring(char * s, char ** words, int wordsSize, int* returnSize){
    int*    pRet        = NULL;         //保存结果集
    int*    pTmpRet     = NULL;         //保存字符串中匹配单词结果集
    int*    pWindow     = NULL;         //滑动窗口,一个单词
    bool    bWinRet     = true;
    int     iSlen       = 0;            //输入字符串长度
    int     iWlen       = 0;            //每个单词长度
    int     i           = 0;
    int     j           = 0;

    if ((NULL == s) || (NULL == words) || (0 == wordsSize))
    {
        *returnSize = 0;
        return NULL;
    }

    iSlen = strlen(s);
    iWlen = strlen(words[0]);
    *returnSize = 0;
    
    pRet = (int *)malloc(sizeof(int) * iSlen);              //保存结果
    pWindow = (char *)malloc(sizeof(char) * (iWlen + 1));   //滑动窗口，一个单词
    memset(pWindow, 0x00, sizeof(char) * (iWlen + 1));
    pTmpRet = (int *)malloc(sizeof(int) * wordsSize);       //保存每一次单词匹配的结果
    
    //1，遍历字符串一遍，进行窗口滑动
    for (i = 0; i <= (iSlen - (iWlen * wordsSize)); i++)
    {
        memset(pTmpRet, 0x00, sizeof(int) * wordsSize);
        bWinRet = true;
        //2，依次将窗口中的单词做匹配
        for (j = i; j < (i + iWlen * wordsSize); j += iWlen)
        {
//            printf("[1] i=%d, j=%d, slen=%d, wlen=%d, wSize=%d\n", i, j, iSlen, iWlen, wordsSize);
            memcpy(&pWindow[0], &s[j], iWlen);

            if (false == matchWords(pWindow, words, wordsSize, pTmpRet))
            {
                bWinRet = false;
                break;
            }
//            printf("[2] i=%d, j=%d, slen=%d, wlen=%d, wSize=%d\n", i, j, iSlen, iWlen, wordsSize);
        }

//        printf("[3] i=%d, j=%d, slen=%d, wlen=%d, wSize=%d\n", i, j, iSlen, iWlen, wordsSize);
        //3，检查匹配结果
        if ((bWinRet) && (true == checkRetFlag(pTmpRet, wordsSize)))
        {
            pRet[*returnSize] = i;
            *returnSize += 1;
        }
    }

    free(pWindow);
    free(pTmpRet);

    return pRet;
}




/*
//方法一：暴力法，超时
//第一步：循环遍历字符串中单词数组，在字符串中依次找出相匹配的单词，并且把结果标记到数组中
//第二步：循环查询结果数组，查找完整的单词串
void matchWords(char* s, char** words, int wordsSize, int* pRet){
    int     iSlen       = strlen(s);
    int     iWlen       = strlen(words[0]);
    int     i           = 0;
    int     j           = 0;

    for (i = 0; i < iSlen; i++)
    {
        for (j = 0; j < wordsSize; j++)
        {
            if (s[i] == words[j][0])
            {
                if (0 == strncmp(&s[i], &words[j][0], iWlen))
                {
                    //匹配单词成功
                    pRet[i] = j;
//                    i += iWlen - 1;
                    break;
                }
            }
        }
    }
    return;
}

int findRet(int* pWord, int sLen, char** words, int wordsSize, int* pRet){
    int     i           = 0;
    int     j           = 0;
    int     k           = 0;
    int     iTmpRet     = 0;
    int     iRetNum     = 0;
    int     iTmp        = 0;
    int     wordLen     = strlen(words[0]);
    int     iRep        = 0;

    int     iTmpBuf[wordsSize];

    for (i = 0; i < sLen; i++)
    {
        printf("[1]: i=%d, word=%d, len=%d, wordsSize=%d\n", i, pWord[i], wordLen, wordsSize);
        if (pWord[i] != 0xffffffff)
        {
            //在结果数组中找到一个匹配单词，开始检查后面 wordsSize 个单词是否都匹配
            iTmpRet = 1;
            memset(iTmpBuf, 0xffffffff, sizeof(int) * wordsSize);

            for (j = 0; j < wordsSize; j++)
            {
                if (((i + j * wordLen) < sLen) && (pWord[i + j * wordLen] != 0xffffffff))
                {
                    iTmp = pWord[i + j * wordLen];
                    
printf("[2] i=%d, j=%d, iTmp=%d, tmpbuf=%d\n", i, j, iTmp, iTmpBuf[iTmp]);

                    if (iTmpBuf[iTmp] == 0xffffffff)
                    {
                        iTmpBuf[iTmp] = pWord[i + j * wordLen];
                    }
                    else
                    {
                        // 在这里添加单词重复判断，如果该单词是重复的，在iTmpBuf 中也找不到
                        for (iRep = 0; iRep < wordsSize; iRep++)
                        {
                            if (0 == strncmp(&words[iTmp][0], &words[iRep][0], wordLen))
                            {
                                if (iTmpBuf[iRep] == 0xffffffff)
                                {
                                    iTmpBuf[iRep] = pWord[i + j * wordLen];
                                    break;
                                }
                            }
                        }
                    }
                }
                else
                {
                    break;
                }
            }
            
printf("[3] i=%d, j=%d, wordsSize=%d, iRetNum=%d\n", i, j, wordsSize, iRetNum);

            if (j >= wordsSize)
            {
                // 有 wordsSize 个单词都有匹配，还需要判断是否所有的单词都匹配了一遍，而不是由几个单词重复导致的
                for (k = 0; k < wordsSize; k++)
                {
                    if (iTmpBuf[k] == 0xffffffff)
                    {
                        // 没有重复的单词，则匹配不成功
                        iTmpRet = 0;
                        break;
                    }
                }

                if (iTmpRet)
                {
                    // 所有单词匹配成功，保存结果
                    pRet[iRetNum] = i;
                    iRetNum += 1;

//                    i += wordLen - 1;
                }
                else
                {
                    // 没有所有单词匹配成功
//                    i += wordLen - 1;
                }
            }
            else
            {
                // 没有 wordsSize 个单词匹配，可能只匹配了一两个
//                i += j * wordLen - 1;
            }

    printf("[4] i=%d, j=%d\n", i, j);

        }
    }
    return iRetNum;
}

int* findSubstring(char * s, char ** words, int wordsSize, int* returnSize){
    int*    pRet        = NULL;         //保存结果集
    int*    pTmpRet     = NULL;         //保存字符串中匹配单词结果集
    int     iSlen       = strlen(s);

    int i = 0;

    if ((NULL == s) || (NULL == words) || (0 == wordsSize))
    {
        *returnSize = 0;
        return NULL;
    }

    pRet = (int *)malloc(sizeof(int) * iSlen);
    pTmpRet = (int *)malloc(sizeof(int) * iSlen);
    memset(pTmpRet, 0xffffffff, sizeof(int) * iSlen);

    //第一步，在字符串中依次找出相匹配的单词，并且把结果标记到数组中
    matchWords(s, words, wordsSize, pTmpRet);

    for (i = 0; i < iSlen; i++)
    {
        printf("%d ", pTmpRet[i]);
    }
    printf("\n");

    //第二步，检查结果数组 pTmpRet 查看是否有满足所有单词串联的结果
    *returnSize = findRet(pTmpRet, iSlen, words, wordsSize, pRet);

    if (0 == *returnSize)
    {
        return NULL;
    }
    else
    {
        return pRet;
    }
}
*/
```