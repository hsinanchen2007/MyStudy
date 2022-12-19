执行结果：通过
显示详情
执行用时 :0 ms, 在所有 C 提交中击败了100.00%的用户
内存消耗 :5.2 MB, 在所有 C 提交中击败了100.00%的用户

```
#define LEN_MAX 1000
char * smallestSubsequence(char * text){
    if (text == NULL) return NULL;
    int set[LEN_MAX] = {0};
    int len = strlen(text);
    for (int i = 0; i < len; ++i) set[text[i] - 'a']++;
    char *ret = (char *)malloc(len + 1);
    int retnum = 0;
    int cur = 0;
    while(cur < len) {
        if (set[text[cur] - 'a'] == 0) {
            cur++;
            continue;
        }
        int min = cur;
        int tmpset[LEN_MAX] = {0};
        memcpy(tmpset, set, LEN_MAX);
        for (int i = min; i < len; ++i) {
            if (tmpset[text[i] - 'a'] == 0) continue;
            min = text[i] < text[min] ? i : min;
            if (text[min] == 'a') break;
            tmpset[text[i] - 'a']--;
            if (tmpset[text[i] - 'a'] == 0) break;
        }
        ret[retnum++] = text[min];
        for (int i = cur; i < min; ++i) {
            if (set[text[i] - 'a']) set[text[i] - 'a']--;
        }
        set[text[min] - 'a'] = 0;
        cur = min + 1;
    }
    ret[retnum] = '\0';
    return ret;
}
```
