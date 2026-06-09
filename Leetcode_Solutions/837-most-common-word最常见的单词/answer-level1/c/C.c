### 解题思路
这题用**C语言**做应该不算简单难度~
主要2个点：
1. 循环怎么写。用2个索引记住每次找到单词的起始位置和结束位置：wordSt和wordEt
      wordSt找第一个字母，wordEt找第一个非字母，单词长度为wordLen = wordEt - wordSt
      单词与ban中的禁用单词比较，如果有则继续往下找单词，如果没有则记录单词，count计数++
2. 测试用例考虑特殊情况：字符串不是以标点符号结束的。`"Bob"`测试用例可以测出，需要添加如下代码
```c
    if (j == len) {
        wordEt = len;
    }
```
### 代码

```c
struct wordCount {
    int count;
    char word[20];
};
char * mostCommonWord(char * paragraph, char ** banned, int bannedSize)
{
    int len = strlen(paragraph);
    int i;
    for (i = 0; i < len; i++) {
        if (paragraph[i] >= 'A' && paragraph[i] <= 'Z') {
            paragraph[i] += 32;
        }
    }
    struct wordCount wordCnt[500];
    for (i = 0; i < 500; i++) {
        wordCnt[i].count = 0;
        strcpy(wordCnt[i].word, "0");
    }
    int wordSt = 0;
    int wordEt = 0;
    int j, k;
    int wordLen = 0;
    int isBan = 0;
    int wordNum = 0;
    int flag = 0;
    while (wordEt < len && wordSt < len) {
        flag = 0;
        isBan = 0;
        for (j = wordSt; j < len; j++) {
            if (paragraph[j] >= 'a' && paragraph[j] <= 'z') {
                wordSt = j;
                break;
            }
        }
        wordEt = wordSt + 1;
        for (j = wordEt; j < len; j++) {
            if (paragraph[j] > 'z' || paragraph[j] < 'a') {
                wordEt = j;
                break;
            }
        }
        if (j == len) {
            wordEt = len;
        }
        wordLen = wordEt - wordSt;
        for (i = 0; i < bannedSize; i++) {
            if (strncmp(paragraph+wordSt, banned[i], wordLen) == 0) {
                isBan = 1;
                break;
            }
        }
        if (isBan == 0) {
            for (i = 0; i < wordNum; i++) {
                if (strncmp(wordCnt[i].word, paragraph + wordSt, wordLen) == 0) {
                    flag = 1;
                    wordCnt[i].count++;
                    break;
                }
            }
            if (flag == 0) {
                strncpy(wordCnt[wordNum].word, paragraph+wordSt, wordLen);
                wordCnt[wordNum].word[wordLen] = '\0';
                wordCnt[wordNum].count++;
                wordNum++;
            }
        }
        wordSt = wordEt + 1;
    }
    int max = 0;
    int index = -1;
    for (i = 0; i < wordNum; i++) {
        // printf("word: %s, cnt: %d\n", wordCnt[i].word, wordCnt[i].count);
        if (wordCnt[i].count > max) {
            max = wordCnt[i].count;
            index = i;
        }
    }
    char *res = (char *)malloc(sizeof(char) * 20);
    strcpy(res, wordCnt[index].word);
    return res;
}
```