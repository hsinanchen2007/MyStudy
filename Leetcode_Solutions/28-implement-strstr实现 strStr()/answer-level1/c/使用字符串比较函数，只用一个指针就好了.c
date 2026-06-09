### 解题思路
i <= size - len；
判断循环进行条件，注意size=len的时候

### 代码

```c
int strStr(char * haystack, char * needle){
    if(*needle == '\0') return 0;
    int len = strlen(needle);
    int size = strlen(haystack);
    int flag;
    for(int i = 0; i <= size - len; i++){
        if(haystack[i] == needle[0]){
            flag = strncmp(haystack + i, needle, len);
            if(0 == flag) return i;
        }
    }
    return -1;
}
```