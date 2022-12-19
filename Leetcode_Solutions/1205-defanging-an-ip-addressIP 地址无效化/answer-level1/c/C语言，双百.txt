### 解题思路
双指针

### 代码

```c
char * defangIPaddr(char * address){
    char *ret = malloc(sizeof(char) * (strlen(address) + 7));
    memset(ret, 0, sizeof(char) * (strlen(address) + 7));
    int j = 0;
    for (int i = 0; i < strlen(address); i++){
        if (address[i] != '.') {
            ret[j++] = address[i];
        } else {
            ret[j++] = '[';
            ret[j++] = '.';
            ret[j++] = ']';
        }
    }
    ret[j] = '\0';
    return ret;
}
```