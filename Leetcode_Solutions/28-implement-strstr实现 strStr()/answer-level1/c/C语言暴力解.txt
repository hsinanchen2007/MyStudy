### 解题思路
逐个字符比较

### 代码

```c
int strStr(char * haystack, char * needle){
    int len1 = strlen(haystack);
    int len2 = strlen(needle);
    if(len2 == 0)
        return 0;
    for(int i = 0; i < len1; i++){
        if(haystack[i] == needle[0]){
            for(int j = 0; j < len2; j++){
                if(needle[j] != haystack[i+j])
                    break;
                if(j == len2 - 1)
                    return i;
            }
        }
    }
    return -1;
}
```