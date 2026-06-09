### 解题思路
此处撰写解题思路
匹配成功后将最后一个字符的位置标记为true，然后剩下部分要是也能匹配成功，则完成匹配

标记过的位置就不再重复匹配了


### 代码

```c
bool check(char * s, char ** wordDict, int wordDictSize, bool *flag) {
    int len;
    //printf("%s\n", s);
    for (int i = 0; i < wordDictSize; i++) {
        len = strlen(wordDict[i]);
        if (strncmp(s, wordDict[i], len) == 0 && !flag[len - 1]) {
            //printf("%s %d\n", s, len);
            flag[len - 1] = true;
            if (strlen(s) == len || check(&s[len], wordDict, wordDictSize, &flag[len])) {
                return true;
            }
        }
    }
    return false;
}

bool wordBreak(char * s, char ** wordDict, int wordDictSize){
    int len;
    bool *flag;

    len = strlen(s);
    flag = (bool *)malloc(sizeof(bool) * len);
    memset(flag, 0, sizeof(bool) * len);
    return check(s, wordDict, wordDictSize, flag);
}
```