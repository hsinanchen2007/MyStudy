执行用时 :0 ms，在所有 C 提交中击败了100.00%的用户 内存消耗 :7.2 MB，在所有 C 提交中击败了76.32%的用户
```c
int lengthOfLongestSubstring(char * s) {
    int table[0xFF];
    memset(table, -1, sizeof(table));
    int maxlen = 0;
    int idx = 0;
    int startidx = 0;
    int findidx = 0;
    int ch;
    while ((ch = s[idx]) != '\0') {
        findidx = table[ch];
        if (findidx >= startidx) {
            int len = idx - startidx;
            maxlen = len > maxlen ? len : maxlen;
            startidx = findidx + 1;
        }
        table[ch] = idx;
        ++idx;
    }
    int len = idx - startidx;
    maxlen = len > maxlen ? len : maxlen;
    return maxlen;
}
```
