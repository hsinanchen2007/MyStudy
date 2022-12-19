

```
int strStr(char * haystack, char * needle){
    int len0 = strlen(haystack);
    int len1 = strlen(needle);
    int i;
    if (len0 < len1) {
        return -1;
    }
    for(i=0;i<len0-len1+1; i++) {
        if(strncmp(haystack+i, needle, len1) == 0) {
            return i;
        }
    }
    return -1;
}
```
