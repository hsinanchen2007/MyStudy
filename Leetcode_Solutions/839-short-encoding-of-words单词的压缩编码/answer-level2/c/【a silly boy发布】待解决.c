![image.png](https://pic.leetcode-cn.com/95e0ed5cbc7e99eff07544907b5d868a63742e725f900dee38a8c5102851128e-image.png)

```
int cmp(const void *a, const void *b)
{
    return strlen(*(char **)b) - strlen(*(char **)a);
}

bool isHasSameStr(char **exitStr, int exitStrNum, char *inputStr)
{
    int i;
    int j;
    bool isSame = true;
    int exitStrLen;
    int inputStrLen = strlen(inputStr);

    for (i = 0; i < exitStrNum; i++) {
        exitStrLen = strlen(exitStr[i]);
        for (j = exitStrLen - inputStrLen; j < exitStrLen; j++) {
            if (exitStr[i][j] != inputStr[j - (exitStrLen - inputStrLen)]) {
                isSame = false;
            }
        }
        if (isSame == true) {
            return true;
        }
    }
    return false;
}

int minimumLengthEncoding(char ** words, int wordsSize)
{
    if ((words == NULL) || (wordsSize == 0)) {
        return 0;
    }

    char **returnStr;
    int returnStrNum = 0;
    int maxNum;
    int i;
    int lenSubStr;
    int returnValue = 0;

    qsort(words, wordsSize, sizeof(words[0]), cmp);
    /*
    for (i = 0; i < wordsSize; i++) {
        printf("words[%d]: %s\n", i, words[i]);
    }
    */

    maxNum = strlen(words[0]) + 1;
    returnStr = (char **)malloc(wordsSize * sizeof(char *));

    for (i = 0; i < wordsSize; i++) {
        returnStr[i] = (char *)malloc(maxNum * sizeof(char));
    }

    returnStr[0] = (char *)malloc(maxNum * sizeof(char));
    memcpy(returnStr[0], words[0], maxNum * sizeof(char));
    returnStrNum++;

    for (i = 1; i < wordsSize; i++) {
        if (words[i] != NULL) {
            if (isHasSameStr(returnStr, returnStrNum, words[i]) == true) {
                continue;
            } else {
                lenSubStr = strlen(words[i]) + 1;
                returnStr[returnStrNum] = (char *)malloc(lenSubStr * sizeof(char));
                memcpy(returnStr[returnStrNum], words[i], lenSubStr * sizeof(char));
                returnStrNum++;
            }
        }
    }

    for (i = 0; i < returnStrNum; i++) {
        returnValue = returnValue + strlen(returnStr[i]) + 1;
    }

    return returnValue;
}
```
