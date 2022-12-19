### 解题思路
遍历一次即可

### 代码

```c
char * freqAlphabets(char * s){
    char *ret = (char *)malloc(sizeof(char) * 1000);
    int len = 0;
    for (int i = 0; i < strlen(s);) {
        if (i + 2 < strlen(s) && s[i + 2] == '#') {
            int tmp = (s[i] - '0') * 10 + (s[i + 1] - '0');
            char c = tmp - 1 + 'a';
            ret[len++] = c;
            i += 3;
        } else {
            char c = s[i] - '1' + 'a';
            ret[len++] = c;
            i++;
        }
    }
    ret[len] = '\0';
    return ret;
}
```