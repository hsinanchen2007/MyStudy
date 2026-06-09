```
char * longestPalindrome(char * s){
    int len = strlen(s);
    int maxSubStrLen = 0;
    int startIdx, endIdx;
    int searchIdx = 0, searchLen = 1;
    int i, m, n;
    if (len <= 1) {
        return s;
    }
    while (searchIdx < len) {
        for (i = searchIdx + 1; i < len; i++){
            if (s[searchIdx] != s[i]) {
                break;
            }
            searchLen++;
        }
        m = i;
        n = searchIdx - 1;
        while ((n >= 0) && (m < len)) {
            if (s[n] != s[m]) {
                break;
            }
            m++;
            n--;
            searchLen += 2;   
        }
        if (searchLen > maxSubStrLen){
            maxSubStrLen = searchLen;
            startIdx = n + 1;
            endIdx = m - 1;
        }
        searchLen = 1;
        searchIdx ++;
    }
    s[endIdx + 1] = '\0';
    return &s[startIdx];
}
```
