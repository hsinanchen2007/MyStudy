一定要注意循环判断条件的等号成立

### 代码

```c
int strStr(char * haystack, char * needle){
    int srcLen = strlen(haystack);
    int desLen = strlen(needle);
    if(desLen == 0) {
        return 0;
    }
    for(int i = 0; i <= (srcLen - desLen); i++) {
        if((haystack[i] == needle[0]) && (strncmp(&haystack[i],needle,desLen) == 0)) {
            return i;
        }
    }
    return -1;
}
```