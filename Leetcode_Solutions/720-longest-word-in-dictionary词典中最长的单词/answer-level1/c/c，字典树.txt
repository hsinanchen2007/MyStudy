### 解题思路
1. 建一个字典树，遍历word加入字典树。但是结果需要在遍历一次words[i], 判断每个words[i]减少一个字母是否在字典树前缀中，因为可能先出现ap,后出现a,建字典树的遍历不知道ap也是符合要求的
2. 所以先用qsort对words按strlen结果排个序。

### 代码

```c
typedef struct dictTree {
    int c;
    int isEnd;
    struct dictTree *next[26];
} DICTTREE;

int insertWord(DICTTREE *d, char *s) {
    int i;
    bool flag = true;
    DICTTREE *cur = d;
    for (i=0; i<strlen(s); i++) {
        if (cur->next[s[i]-'a'] == NULL) {
            cur->next[s[i]-'a'] = (DICTTREE*)malloc(sizeof(DICTTREE));
            (void)memset(cur->next[s[i]-'a'], 0, sizeof(DICTTREE));
            cur->next[s[i]-'a']->c = s[i];
        }
        if (i == strlen(s)-1) {
            cur->next[s[i]-'a']->isEnd = true;
            return flag;
        }
        if (cur->next[s[i]-'a']->isEnd == false) {
            flag = false;
        }
        cur = cur->next[s[i]-'a'];
    }
    return flag;
}

int cmp(const void *a, const void *b) {
    return strlen(*(char**)a) - strlen(*(char**)b);
}

char * longestWord(char ** words, int wordsSize){
    qsort(words, wordsSize, sizeof(char*), cmp);
    DICTTREE d = {0};
    char *ans = NULL;
    int i;
    for (i=0; i<wordsSize; i++) {
        if (!insertWord(&d, words[i])) continue;

        //printf("complete word %s\n", words[i]);

        if (!ans) ans = words[i];
        else if (strlen(words[i]) > strlen(ans) ||
            (strlen(words[i]) == strlen(ans) && strcmp(words[i], ans) < 0)) {       
            ans = words[i];
        }
    }

    return ans;
}
```