- **执行用时 :12 ms, 在所有C提交中击败了88.41%的用户**
- **内存消耗 :7.1 MB, 在所有C提交中击败了79.10%的用户**


```
/**
* 字符串s前len位是否包含字符c
* return 0：不包含 1：包含
*/
int contains(char *s, char c, int len) {
    int i = 0;
    while(s[i] != NULL && i < len) {
        if(s[i] == c){
            return 1;
        }
        i++;
    }
    return 0;
}

int lengthOfLongestSubstring(char* s){
    int len = 0;
    while(s[len] != NULL) {
        // 计算字符串s的长度
        len++;
    }

    int i = 0;
    int j = 1;
    int maxLen = 0;
    // 如果从i位开始的字符串到末尾的长度小于最大字符串的长度，则不需要继续计算
    while(s[i] != NULL && (len - i > maxLen)) {
        while(s[j] != NULL && (contains( &s[i], s[j], j - i) == 0)) {
            // 遍历子串，如果前面几位都不包含当前的字符，则继续遍历；如果包含，则退出循环，计算下一个子串
            // 如果之前计算过的子串，则不继续计算
            // 例如，abcdabcd，当计算以首位开始的子串最长长度为abcd的字符串，因为bcd是abcd的子串，则不需要重复计算
            // 计算以b开头的子串时，直接判断上一次遍历j=4，即a是否属于bcd
            j++;
        }
        if(j - i > maxLen) {
            maxLen = j - i;
        }
        i++;
    }
    return maxLen;
}
```