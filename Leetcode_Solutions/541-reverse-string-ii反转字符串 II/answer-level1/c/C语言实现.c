
C语言实现
```C []
char * reverseStr(char * s, int k){
    int len = strlen(s);
    if (len == 0) return NULL;
    if (k < 2) return s;
    int i, start, end;
    char tmp;
    for (i = 0; i < len; i += 2 * k){
        start = i;
        end = (len > i + k) ? i + k - 1 : len - 1;
        while (start < end) {
            tmp = s[start];
            s[start++] = s[end];
            s[end--] = tmp;
        }
    }
    return s;
}
```
