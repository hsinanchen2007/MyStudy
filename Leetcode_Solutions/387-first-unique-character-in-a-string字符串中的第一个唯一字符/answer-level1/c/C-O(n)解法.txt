声明int数组，记录每个字母的出现次数，然后遍历字符串如果这个字母的出现次数等于1，直接返回 i（这个字母的下标）否则返回-1


```
int a[27];
int firstUniqChar(char * s){
    memset(a, 0, sizeof(a));
    int len = strlen(s);
    for (int i = 0; i < len; i++)
        a[s[i] - 'a']++;
    for (int i = 0; i < len; i++) {
        if (a[s[i] - 'a'] == 1)
            return i;
    }
    return -1;
}
```