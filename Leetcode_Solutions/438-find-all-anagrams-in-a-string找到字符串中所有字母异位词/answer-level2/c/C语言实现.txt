采用26个字母的hash运算法 + 移动窗口，时间复杂度O(n)
```C []
int* findAnagrams(char * s, char * p, int* returnSize){
    *returnSize = 0;
    int len_s = strlen(s);
    int len_p = strlen(p);
    if (len_s < len_p)
        return NULL;

    int i, j, len = len_s - len_p + 1;
    int hash[26] = {0};
    for (i = 0; i < len_p; ++i){
        hash[p[i] - 'a']++;
        hash[s[i] - 'a']--;
    }
    int *res = (int*)malloc(len * sizeof(int));
    memset(res, 0, len * sizeof(int));
    char *s2 = s + len_p;
    for (i = 0; i < len; ++i){
        for (j = 0; j < 26; ++j) if (hash[j]) break;
        if (j >= 26) res[(*returnSize)++] = i;
        hash[*s++ - 'a']++;
        if (*s2) hash[*s2++ - 'a']--;
    }
    return res;
}

```
