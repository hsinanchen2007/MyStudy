搞字母表暴力比，1680ms，哈哈，然后在优化下，不用每次都重新计算hash表。
优化前：
```
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int arrayP[26] = {0};
int arrayS[26] = {0};

void calculatePLetter(char* string) {
    int len = strlen(string);
    for (int i = 0; i < len; i++) {
        arrayP[string[i] - 'a'] += 1;
    }
    return;
}

void calculateTmpLetter(char* str) {
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        arrayS[str[i] - 'a'] += 1;
    }
    return;
}

int judgeIfSameLetter(int* P, int* S) {
    int flg = 1;
    for (int i = 0; i < 26; i++) {
        if (S[i] != P[i]) {
            flg = 0;
            break;
        }
    }
    return flg;
}

int* findAnagrams(char * s, char * p, int* returnSize){
    *returnSize = 0;
    int lenP = strlen(p);
    int lenS = strlen(s);
    int* res = (int*)calloc(20100, sizeof(int));
    char* tmp = (char*)calloc(lenP + 1, sizeof(char));

    memset(arrayP, 0, sizeof(int) * 26);
    memset(arrayS, 0, sizeof(int) * 26);

    calculatePLetter(p);
    for (int i = 0; i < lenS; i++) {
        int ret = 0;
        memset(tmp, 0, sizeof(char) * (lenP + 1));
        memset(arrayS, 0, sizeof(int) * 26);
        strncpy(tmp, s, lenP);
        calculateTmpLetter(tmp);
        ret = judgeIfSameLetter(arrayP, arrayS);
        if (ret == 1) {
            res[*returnSize] = i;
            (*returnSize)++;
        }
        s += 1;
    }
    if (tmp != NULL) {
        free(tmp);
        tmp = NULL;
    }
    return res;
}
```
优化后，移动窗口，不用重复计算S的hash，可以达到30ms以内：
```
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int arrayP[26] = {0};
int arrayS[26] = {0};

void calculatePLetter(char* string) {
    int len = strlen(string);
    for (int i = 0; i < len; i++) {
        arrayP[string[i] - 'a'] += 1;
    }
    return;
}

void calculateTmpLetter(char* str) {
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        arrayS[str[i] - 'a'] += 1;
    }
    return;
}

int judgeIfSameLetter(int* P, int* S) {
    int flg = 1;
    for (int i = 0; i < 26; i++) {
        if (S[i] != P[i]) {
            flg = 0;
            break;
        }
    }
    return flg;
}

int* findAnagrams(char * s, char * p, int* returnSize){
    *returnSize = 0;
    int ret = 0;
    int lenP = strlen(p);
    int lenS = strlen(s);
    int* res = (int*)calloc(20100, sizeof(int));
    char* tmp = (char*)calloc(lenP + 1, sizeof(char));

    memset(arrayP, 0, sizeof(int) * 26);
    memset(arrayS, 0, sizeof(int) * 26);

    calculatePLetter(p);
    /* S的话只算第一次，后面直接对全局数组做操作(移动窗口) */
    strncpy(tmp, s, lenP);
    calculateTmpLetter(tmp);
    ret = judgeIfSameLetter(arrayP, arrayS);
    if (ret == 1) {
        res[*returnSize] = 0;
        (*returnSize)++;
    }
    for (int i = 1; i < lenS - lenP + 1; i++) {
        ret = 0;
        /* 移动窗口：把上一个字符在hash表里干掉，增加下一个字符在hash表里 */
        arrayS[s[i - 1] - 'a'] -= 1;
        arrayS[s[i + (lenP - 1)] - 'a'] += 1;
        ret = judgeIfSameLetter(arrayP, arrayS);
        if (ret == 1) {
            res[*returnSize] = i;
            (*returnSize)++;
        }
    }
    if (tmp != NULL) {
        free(tmp);
        tmp = NULL;
    }
    return res;
}
```

