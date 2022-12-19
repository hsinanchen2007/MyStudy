### 解题思路
方法一：
1,先决定一行放多少个单词
2,确定放多少个单词之后决定一行中空格如何分配

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
//方法一：
//1,先决定一行放多少个单词
//2,确定放多少个单词之后决定一行中空格如何分配

//函数一：填写单词，左右对齐，合理分配空格
void fillWords(char** words, int iNum, char* pRet, int iLen, int maxWidth){
    int     i               = 0;
    int     iSpaceNum       = 0;    //空格总数
    int     iAveNum         = 0;    //平均空格数
    int     iresNum         = 0;    //剩余空格数
    int     ipos            = 0;

    //1,计算空格平均数及剩余空格数
    iSpaceNum = maxWidth - iLen;
    if (iNum > 1)
    {
        iAveNum = iSpaceNum / (iNum - 1);
        iresNum = iSpaceNum % (iNum - 1);
    }

    //2,将结果先全部填上空格
    for (i = 0; i < maxWidth; i++)
    {
        pRet[i] = ' ';
    }

    //3,将单词插入相应的位置
    for (i = 0; i < iNum; i++)
    {
        memcpy(&pRet[ipos], words[i], strlen(words[i]));
        ipos += strlen(words[i]) + iAveNum;
        if (iresNum > 0)
        {
            //如果有剩余空格数，则从左边起，一个单词多填一个空格
            ipos += 1;
            iresNum -= 1;
        } 
    }

    return;
}

//函数二：最后一行处理，左对齐
void fillWordsLastRow(char** words, int iNum, char* pRet, int maxWidth){
    int     i               = 0;
    int     ipos            = 0;

    //1,将结果先全部填上空格
    for (i = 0; i < maxWidth; i++)
    {
        pRet[i] = ' ';
    }

    //2,将单词插入相应的位置
    for (i = 0; i < iNum; i++)
    {
        memcpy(&pRet[ipos], words[i], strlen(words[i]));
        ipos += strlen(words[i]) + 1;
    }

    return;
}

char ** fullJustify(char ** words, int wordsSize, int maxWidth, int* returnSize){
    int         i           = 0;
    int         iTmpLen     = 0;
    int         iTmpNum     = 0;
    int         iPos        = 0;
    int         iRetSize    = 0;
    char**      pRet        = NULL;

    if ((NULL == words) || (0 == wordsSize)) return NULL;

    //1,初始化
    pRet = (char**)malloc(sizeof(char*) * wordsSize);
    memset(pRet, 0x00, sizeof(char*) * wordsSize);

    //2,循环处理单词
    for (i = 0; i < wordsSize; i++)
    {
        if (iTmpLen + strlen(words[i]) + iTmpNum > maxWidth)
        {
//            printf("[1][i=%d][num=%d][len1=%d][len2=%d][%s]\n", i, iTmpNum, iTmpLen, strlen(words[i]), words[i]);
            //3，将未超过最大长度的单词填写到结果中
            pRet[iRetSize] = (char*)malloc(sizeof(char) * (maxWidth + 1));
            memset(pRet[iRetSize], 0x00, sizeof(char) * (maxWidth + 1));

            fillWords(&words[iPos], iTmpNum, pRet[iRetSize], iTmpLen, maxWidth);

            iPos = i;
            iTmpNum = 0;
            iTmpLen = 0;
            iRetSize += 1;
        }

        iTmpNum += 1;
        iTmpLen += strlen(words[i]);
    }

//    printf("[2][ipos=%d][num=%d][size=%d][%s]\n", iPos, iTmpNum, iRetSize, words[iPos]);
    //4,最后一行处理
    if (iPos <= wordsSize - 1)
    {
        pRet[iRetSize] = (char*)malloc(sizeof(char) * (maxWidth + 1));
        memset(pRet[iRetSize], 0x00, sizeof(char) * (maxWidth + 1));

        fillWordsLastRow(&words[iPos], iTmpNum, pRet[iRetSize], maxWidth);
        iRetSize += 1;
    }

//    printf("[3][size=%d]\n", iRetSize);
    //5,返回
    *returnSize = iRetSize;
    return pRet;
}
```