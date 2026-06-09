通过将s翻转，然后比对翻转前和翻转后的结果来判断。108ms，7.8M
```
char * longestPalindrome(char * s){
    int i, j, k;
    int startIdx = 0;
    int outLen = 1;
    int len = strlen(s);
    char *rev = (char *)malloc(len + 1);
    for (i = 0; i < len; i++) {
        *(rev + i) = *(s + len - i - 1); // 将S颠倒，用来做比较
    }
    for (i = 0; i < len; i++) {
        for (j = 0; j <= len - i - outLen; j++) {
            if (s[i] == rev[j]) {
                if (strncmp(s + i, rev + j, len - i - j) != 0) { // s和翻转后的s直接比对结果
                    continue;
                } 
                outLen = len - i - j;
                startIdx = (outLen == (len - i - j)) ? i : startIdx;
            }
        }
    }
    char *out = (char *)malloc(outLen + 1);
    memcpy(out, s + startIdx, outLen);
    *(out + outLen) = '\0';
    return out;
}
```

