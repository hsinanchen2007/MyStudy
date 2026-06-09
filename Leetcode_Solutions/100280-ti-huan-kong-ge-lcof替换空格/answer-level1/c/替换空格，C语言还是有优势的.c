执行用时 :0 ms, 在所有 C 提交中击败了100.00%的用户
内存消耗 :6.8 MB, 在所有 C 提交中击败了100.00%的用户

```
char* replaceSpace(char* s){
    if (s == NULL) {
        return NULL;
    }
    
    int i = 0;
    int j = 0;
    int len = strlen(s);
    char* res = (char*)malloc(3 * len + 1);
    while (*(s + i) != '\0') {
        if (*(s + i) != ' ') {
            *(res + j++) = *(s + i++);
        } else {
            *(res + j++) = '%';
            *(res + j++) = '2';
            *(res + j++) = '0';
            i++;
        }
    }
    *(res + j) = '\0';
    return res;
}
```
