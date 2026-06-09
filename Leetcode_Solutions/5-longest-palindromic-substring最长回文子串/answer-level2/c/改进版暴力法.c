### 解题思路
判断剩余字符串长度<maxlen，跳出循环

### 代码

```c
bool isPalindrome(char* b, char* e) {
    while (b < e && *b == *e) {
        ++b;
        --e;
    }
    return b >= e;
}

char * longestPalindrome(char * s){
    if (!s || !*s) return s;
    char* e = s;
    while (*e) {++e;}
    --e;
    char* maxpos = s;
    int maxlen = 1;
    char* pb = s;
    char* pe = e;
    while (e - pb >= maxlen) {
        pe = e;
        while (pe - pb >= maxlen) {
            if (*pe == *pb && isPalindrome(pb, pe)) {
                int len = pe - pb + 1;
                if (len > maxlen) {
                    maxpos = pb;
                    maxlen = len;
                }
                break;
            }
            --pe;
        }
        ++pb;
    }
    maxpos[maxlen] = '\0';
    return maxpos;
}
```