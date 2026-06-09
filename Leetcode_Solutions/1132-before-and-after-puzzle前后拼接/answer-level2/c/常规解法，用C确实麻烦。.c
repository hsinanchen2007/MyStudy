执行用时 : 12 ms , 在所有 C 提交中击败了 82.35% 的用户；内存消耗 : 8.9 MB , 在所有 C 提交中击败了 100.00% 的用户。

```
int cmpStr(const void *a, const void *b)
{
    char *str1 = *(char **)a;
    char *str2 = *(char **)b;
    return strcmp(str1, str2);   
}

char ** beforeAndAfterPuzzles(char ** phrases, int phrasesSize, int* returnSize)
{
    char **retPhreases    = (char **)malloc(sizeof(char *) * phrasesSize * 2);
    char **tmpRetPhreases = (char **)malloc(sizeof(char *) * phrasesSize * 2);
    int    retSize        = 0;
    int    tmpRetSize     = 0;

    // 遍历每一个短语
    for (int i = 0; i < phrasesSize; i++)
    {
        printf("**** i = %d\n", i);
        char *curPhrease = phrases[i];
        int   curPhreaseLen = strlen(curPhrease);

        // 短语第一个单词起始位置就是短语头，找到第一个空格计算其长度
        char *firstWord    = curPhrease;
        // 默认没找到第一个空格，说明短语只有一个单词，第一个单词长度等于短语长度
        int   firstWordLen = curPhreaseLen; 
        char *firstSpace   = strchr(curPhrease, ' ');
        // 找到第一个空格，计算第一个单词长度
        if (NULL != firstSpace)
        {
            firstWordLen = firstSpace - firstWord;
        }

        // 找到短语最后一个单词起始位置，最后一个空格+1，默认短语只有一个单词，没有空格
        char *lastWord   = curPhrease;
        int  lastWordLen = curPhreaseLen;
        char *lastSpace  = strrchr(curPhrease, ' ');
        // 找到最后一个空格，计算最后一个单词长度
        if (NULL != lastSpace)
        {
            lastWord     = lastSpace + 1;
            lastWordLen  = strlen(lastWord);
        }

        // 遍历i之后的短语，与i进行匹配
        for (int j = i + 1; j < phrasesSize; j++)
        {
            char *tmpPhrease = phrases[j];
            int   tmpPhreaseLen = strlen(tmpPhrease);
            
            // 获取j最后一个空格（短语）位置，默认j只有一个单词
            char *cmpLastWord  = tmpPhrease;
            int   cmpLastLen   = tmpPhreaseLen;
            char *cmpLastSpace = strrchr(tmpPhrease, ' ');
            // 找到最后一个空格，计算最后一个单词长度
            if (NULL != cmpLastSpace)
            {
                cmpLastWord = cmpLastSpace + 1;
                cmpLastLen = strlen(cmpLastWord);
            }            

            // 尝试用i第一个单词去和其他短语最后一个单词(firstWordLen长度的字符)匹配；
            if ((firstWordLen == cmpLastLen) 
                && (0 == strncmp(firstWord, cmpLastWord, firstWordLen)))
            {
                tmpRetPhreases[tmpRetSize] = (char *)malloc((curPhreaseLen + tmpPhreaseLen));
                strcpy(tmpRetPhreases[tmpRetSize], tmpPhrease);
                strcat(tmpRetPhreases[tmpRetSize], firstWord + firstWordLen);
                tmpRetSize++;
            }

            // 获取j第一个空格（短语）位置，默认j只有一个单词
            char *cmpFirstWord  = tmpPhrease;
            int   cmpFirstLen   = tmpPhreaseLen;
            char *cmpFirstSpace = strchr(tmpPhrease, ' ');
            // 找到第一个空格，计算最后一个单词长度
            if (NULL != cmpLastSpace)
            {
                cmpFirstLen = cmpFirstSpace - cmpFirstWord;
            }  

            // 尝试用最后一个单词去和其他短语第一个单词(lastWordLen长度的字符)匹配；
            if ((lastWordLen == cmpFirstLen)
                && 0 == strncmp(lastWord, cmpFirstWord, lastWordLen))
            {
                tmpRetPhreases[tmpRetSize] = (char *)malloc((curPhreaseLen + tmpPhreaseLen));
                strcpy(tmpRetPhreases[tmpRetSize], curPhrease);
                strcat(tmpRetPhreases[tmpRetSize], cmpFirstWord + cmpFirstLen);
                tmpRetSize++;
            }
        }
    }

    // 对tmpRetPhreases进行排序
    qsort(tmpRetPhreases, tmpRetSize, sizeof(char *), cmpStr);

    // 结果去重
    for (int i = 0; i < tmpRetSize; i++)
    {
        if (i > 0 && 0 == strcmp(tmpRetPhreases[i], tmpRetPhreases[i-1]))
        {
            continue;
        }
        retPhreases[retSize++] = tmpRetPhreases[i];
    }

    *returnSize = retSize;

    return retPhreases;
}
```
