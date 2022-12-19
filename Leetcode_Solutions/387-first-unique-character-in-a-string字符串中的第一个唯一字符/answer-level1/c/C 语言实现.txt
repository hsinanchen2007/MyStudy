C 语言实现
```C []
int firstUniqChar(char * s) {
    int table[26] = {0};
    int i, len = strlen(s);
    for (i = 0; i < len; ++i) table[s[i] - 'a']++;
    for (i = 0; i < len; ++i) if (1 == table[s[i] - 'a']) return i;
    return -1;
}
```