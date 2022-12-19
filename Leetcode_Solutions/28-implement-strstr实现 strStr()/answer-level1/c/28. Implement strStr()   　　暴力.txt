### 解题思路
此处撰写解题思路

### 代码

```c
int strStr(char * haystack, char * needle){
    int i;
    char *s1, *s2;

    if (*needle == '\0')
        return 0;
    for (i = 0; haystack[i] != '\0'; i++) {
        if (haystack[i] == *needle) {
            s1 = haystack + i + 1;
            s2 = needle + 1;
            //printf("%s %s\n",s1, s2);
            while (*s1 != '\0' && *s2 != '\0'){
                //printf("%c %c\n",*s1, *s2);
                if (*s1!= *s2)
                    break;
                s1++, s2++;
            }
            if (*s2 == '\0')
                return i;
        }
    }
    return -1;
}
```