

```
int char_num[128];
int firstUniqChar(char * s){
    if (s == NULL || s[0] == 0) return -1;
    for (int i = 0; i < 128; ++i) char_num[i] = 0;
    for (int i = 0; s[i]; ++i) {
        if (char_num[s[i]]) char_num[s[i]] = -1;
        else                char_num[s[i]] = i+1;//防止下标为0的情况
    }

    int min_len = 0x7fffffff;
    for (int i = 97; i < 123; ++i) {
        if (char_num[i] && char_num[i] != -1 && char_num[i] < min_len) min_len = char_num[i];
    }
    return (min_len == 0x7fffffff ? -1 : min_len - 1);
}
```
