
执行用时 :4 ms, 在所有 c 提交中击败了78.31% 的用户
内存消耗 :7.1 MB, 在所有 c 提交中击败了86.79%的用户
时间复杂度O(m*n) 空间复杂度O(1)

**提高了代码的可读性，但在执行时有冗余部分。**

```
int strStr(char * haystack, char * needle){
    if(*needle == '\0' ) return 0;
    if(*haystack == '\0') return -1;
    char *p = haystack;
    char *q = needle;

    while(*p != '\0'){
        if(*p++ == *q++){
            if(*q == '\0')
                return (p-haystack)-(q-needle);
        }
        else{ 
            p = (p-(q-needle))+1;
            q = needle;
        }
    }
    return -1;
}
```

