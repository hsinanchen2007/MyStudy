# 普通版
```c
#define SIZE 20005
char cash[SIZE];

int Cmp(const void* a, const void* b)
{
    char* aa = *(char**)a;
    char* bb = *(char**)b;
    return strlen(bb) - strlen(aa);
}

int minimumLengthEncoding(char ** words, int wordsSize){
    if (words == NULL || wordsSize == 0) {
        return 0;
    }
    qsort(words, wordsSize, sizeof(char*), Cmp);
    memset(cash, 0, sizeof(cash));
    strcpy(cash, words[0]);
    strcat(cash, "#");
    int i;
    char* findStr = NULL;
    for (i = 1; i < wordsSize; ++i) {
        findStr = strstr(cash, words[i]);
        if (!findStr || *(findStr + strlen(words[i])) != '#') {
            strcat(cash, words[i]);
            strcat(cash, "#");
        }

    }
    return strlen(cash);
}

```

# 优化加速版
```c
#define SIZE 20005
char cash[SIZE];

int Cmp(const void* a, const void* b)
{
    char* aa = *(char**)a;
    char* bb = *(char**)b;
    return strlen(bb) - strlen(aa);
}

static inline int MyStringCopy(char* destStr, int start, char* srcStr)
{
    int i;
    for (i = start; *srcStr; ++i, ++srcStr) {
        destStr[i] = *srcStr;
    }
    destStr[i] = '\0';
    return i;
}

int minimumLengthEncoding(char ** words, int wordsSize){
    if (words == NULL || wordsSize == 0) {
        return 0;
    }
    qsort(words, wordsSize, sizeof(char*), Cmp);
    int ret = 0;
    ret = MyStringCopy(cash, 0, words[0]);
    ret = MyStringCopy(cash, ret, "#");
    int i;
    char* findStr = NULL;
    for (i = 1; i < wordsSize; ++i) {
        findStr = strstr(cash, words[i]);
        if (!findStr || *(findStr + strlen(words[i])) != '#') {
            ret = MyStringCopy(cash, ret, words[i]);
            ret = MyStringCopy(cash, ret, "#");
        }
    }
    return ret;
}

```