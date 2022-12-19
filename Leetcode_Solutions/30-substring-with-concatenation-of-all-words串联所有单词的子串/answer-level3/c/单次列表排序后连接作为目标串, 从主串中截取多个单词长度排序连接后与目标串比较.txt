### 解题思路
> 单次列表排序后连接作为目标串, 从主串中截取多个单词长度排序连接后与目标串比较, 性能一般, 用排序替代搜索,可以减少排列组合搜索的过程;

>注意: 内存操作比较麻烦, 用qsort排序字符串地址时, 传入的参数是 每个元素的地址, 元素的值才是我们的字符串首地址;

- 方案1: 从s中暴力遍历, 每个起点开始选取公共长度, 进行切割比较;
- 方案2: 从s中用```划窗```方法筛选字符组成一样的字符串,然后再进行切割比较;

### 代码

```c [groups1-C排序单词表并串联后暴力求解]
int g_wordLen = 0;

int StrCmpByLen(char *str, char *another, int maxCmpLen)
{
    for (int i = 0; i < maxCmpLen; i++) {
        if (str[i] == another[i]) {
            continue;
        }
        return str[i] - another[i];
    }
    return 0;
}

// 传入字符串首地址, 比较word对应长度的字符; 注意对二级指针的处理!
int CmpStrByChar(const void *a, const void *b)
{
    return StrCmpByLen(*(char **)a, *(char **)b, g_wordLen);
}

// 外部保证入参合法性, 内部不再校验;
void RecordWordStr(char *originStr, char **tempWordsArray, int wordsSize)
{
    for (int i = 0; i < wordsSize; i++) {
        tempWordsArray[i] = originStr + i * g_wordLen;
    }
}

void CatStrFromArray(char *dest, char **array, int arraySize)
{
    int count = 0;
    for (int i = 0; i < arraySize; i++) {
        for (int j = 0; j < g_wordLen; j++) {
            dest[count++] = array[i][j];
        }
    }
}

int FillMatachedPos(char *s, int *resultArray, char **words, int wordsSize, int maxArraySize)
{
    char **tempWordsArray = (char **)malloc(sizeof(char *) * wordsSize);
    if (tempWordsArray == NULL) {
        return 0;
    }
    int commStrLen = g_wordLen * wordsSize + 1;
    char *targetStr = (char *)malloc(sizeof(char) * commStrLen);
    if (targetStr == NULL) {
        free(tempWordsArray);
        return 0;
    }
    char *tempStr = (char *)malloc(sizeof(char) * commStrLen);
    if (tempStr == NULL) {
        free(tempWordsArray);
        free(targetStr);
        return 0;
    }

    qsort(words, wordsSize, sizeof(char *), CmpStrByChar);
    CatStrFromArray(targetStr, words, wordsSize);
    int foundCount = 0;
    for (int i = 0; i < maxArraySize; i++) {
        RecordWordStr(s + i, tempWordsArray, wordsSize);
        qsort(tempWordsArray, wordsSize, sizeof(char *), CmpStrByChar);
        CatStrFromArray(tempStr, tempWordsArray, wordsSize);
        if (StrCmpByLen(targetStr, tempStr, commStrLen - 1) == 0) {
            resultArray[foundCount++] = i;
        }
    }
    free(tempWordsArray);
    free(targetStr);
    free(tempStr);
    return foundCount;
}
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *findSubstring(char *s, char **words, int wordsSize, int *returnSize)
{
    if (s == NULL || words == NULL || returnSize == NULL || wordsSize == 0) {
        if (returnSize != NULL) {
            *returnSize = 0;
        }
        return NULL;
    }
    g_wordLen = strlen(words[0]);
    int commonStrLen = g_wordLen * wordsSize;
    int lenOfStr = strlen(s);
    if (lenOfStr < commonStrLen) {
        *returnSize = 0;
        return NULL;
    }
    int maxArraySize = lenOfStr - commonStrLen + 1;
    int *resultArray = (int *)malloc(sizeof(int) * maxArraySize);
    if (resultArray == NULL) {
        return NULL;
    }
    *returnSize = FillMatachedPos(s, resultArray, words, wordsSize, maxArraySize);
    return resultArray;
}

```
```c [groups1-C排序单词表并串联后划窗求解]
#define MAX_CHAR_TYPES_COUNT 128
int g_wordLen = 0;

int StrCmpByLen(char *str, char *another, int maxCmpLen)
{
    for (int i = 0; i < maxCmpLen; i++) {
        if (str[i] == another[i]) {
            continue;
        }
        return str[i] - another[i];
    }
    return 0;
}

// 传入字符串首地址, 比较word对应长度的字符;
int CmpStrByChar(const void *a, const void *b)
{
    return StrCmpByLen(*(char **)a, *(char **)b, g_wordLen);
}

// 外部保证入参合法性, 内部不再校验;
void RecordWordStr(char *originStr, char **tempWordsArray, int wordsSize)
{
    for (int i = 0; i < wordsSize; i++) {
        tempWordsArray[i] = originStr + i * g_wordLen;
    }
}

void CatStrFromArray(char *dest, char **array, int arraySize)
{
    int count = 0;
    for (int i = 0; i < arraySize; i++) {
        for (int j = 0; j < g_wordLen; j++) {
            dest[count++] = array[i][j];
        }
    }
}

void UpdateWordsCount(int wordsCount[MAX_CHAR_TYPES_COUNT], char *s, int maxCountLen)
{
    for (int i = 0; i < maxCountLen && s[i] != '\0'; i++) {
        wordsCount[s[i]] += 1;
    }
}

int GetNeededWordTypes(int wordsCount[MAX_CHAR_TYPES_COUNT])
{
    int count = 0;
    for (int i = 0; i < MAX_CHAR_TYPES_COUNT; i++) {
        if (wordsCount[i]) {
            count += 1;
        }
    }
    return count;
}

int FillMatachedPos(char *s, int *resultArray, char **words, int wordsSize, int maxArraySize)
{
    char **tempWordsArray = (char **)malloc(sizeof(char *) * wordsSize);
    if (tempWordsArray == NULL) {
        return 0;
    }
    int wordsStrLen = g_wordLen * wordsSize;
    int commStrLen = wordsStrLen + 1;
    char *targetStr = (char *)malloc(sizeof(char) * commStrLen);
    if (targetStr == NULL) {
        free(tempWordsArray);
        return 0;
    }
    char *tempStr = (char *)malloc(sizeof(char) * commStrLen);
    if (tempStr == NULL) {
        free(tempWordsArray);
        free(targetStr);
        return 0;
    }

    qsort(words, wordsSize, sizeof(char *), CmpStrByChar);
    CatStrFromArray(targetStr, words, wordsSize);
    targetStr[wordsStrLen] = '\0';
    int charsInStrCount[MAX_CHAR_TYPES_COUNT] = {0};
    int wordsCount[MAX_CHAR_TYPES_COUNT] = {0};
    UpdateWordsCount(wordsCount, targetStr, wordsStrLen);
    int neededTypes = GetNeededWordTypes(wordsCount);
    int matched = 0;
    int foundCount = 0;
    // 先截取目标长度的子串并初始化母串的计数
    for (int i = 0; i < wordsStrLen - 1; i++) {
        if (wordsCount[s[i]]) {
            charsInStrCount[s[i]]++;
            if (charsInStrCount[s[i]] == wordsCount[s[i]]) {
                matched++;
            }
        }
    }
    for (int i = 0; i < maxArraySize; i++) {
        char last = s[i + wordsStrLen - 1];
        if (wordsCount[last]) {
            charsInStrCount[last]++;
            if (charsInStrCount[last] == wordsCount[last]) {
                matched++;
            }
        }
        if (matched == neededTypes) {
            RecordWordStr(s + i, tempWordsArray, wordsSize);
            qsort(tempWordsArray, wordsSize, sizeof(char *), CmpStrByChar);
            CatStrFromArray(tempStr, tempWordsArray, wordsSize);
            if (StrCmpByLen(targetStr, tempStr, wordsStrLen) == 0) {
                resultArray[foundCount++] = i;
            }
        }
        // 删除首元素
        if (wordsCount[s[i]]) {
            if (charsInStrCount[s[i]] == wordsCount[s[i]]) {
                matched--;
            }
            charsInStrCount[s[i]]--;
        }
    }
    free(tempWordsArray);
    free(targetStr);
    free(tempStr);
    return foundCount;
}
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *findSubstring(char *s, char **words, int wordsSize, int *returnSize)
{
    if (s == NULL || words == NULL || returnSize == NULL || wordsSize == 0) {
        if (returnSize != NULL) {
            *returnSize = 0;
        }
        return NULL;
    }
    g_wordLen = strlen(words[0]);
    int commonStrLen = g_wordLen * wordsSize;
    int lenOfStr = strlen(s);
    if (lenOfStr < commonStrLen) {
        *returnSize = 0;
        return NULL;
    }
    int maxArraySize = lenOfStr - commonStrLen + 1;
    int *resultArray = (int *)malloc(sizeof(int) * maxArraySize);
    if (resultArray == NULL) {
        return NULL;
    }
    *returnSize = FillMatachedPos(s, resultArray, words, wordsSize, maxArraySize);
    return resultArray;
}
```

### 性能表现
```
- 方案1:
执行用时 :408 ms, 在所有 C 提交中击败了65.67%的用户
内存消耗 :35.7 MB, 在所有 C 提交中击败了25.30%的用户

- 方案2:
执行用时 :132 ms, 在所有 C 提交中击败了77.23%的用户
内存消耗 :25.9 MB, 在所有 C 提交中击败了16.33%的用户
```




