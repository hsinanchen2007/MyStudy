```
int lengthOfLongestSubstring(char *s) {
    char *pos[256] = {0,};

    void unset(char *begin, char *end) {
        for (char *p = begin; p<end; p++) {
            pos[*p] = 0;
        }
    }

    char *begin = s;
    int maxn = 0;
    int n = 0;
    char *p = NULL;

    while (*s) {
        if (pos[*s]) {
            n = s - begin;
            if (n > maxn) {
                maxn = n;
            }
            p = pos[*s];
            unset(begin, p+1);
            begin = p+1;
        }
        pos[*s] = s;
        s++;
    }
    n = s - begin;
    if (n > maxn) {
        maxn = n;
    }
    return maxn;
}
```
