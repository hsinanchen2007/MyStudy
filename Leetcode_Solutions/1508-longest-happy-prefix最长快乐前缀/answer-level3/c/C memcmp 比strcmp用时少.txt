### 解题思路
此处撰写解题思路
开始用strcmp，妥妥超时，后来用memcmp就过了
### 代码

```c
char * longestPrefix(char * s){
    int len = strlen(s);
    for (int i = 1; i < len; i++) {
        //printf("cmp %s, num:%d, &s\n", s, len - i, s + i);
        if ((memcmp(s + i, s, len - i)) == 0) {
            return s + i;
        }
    }
    s[0] = '\0';
    return s;
}
```