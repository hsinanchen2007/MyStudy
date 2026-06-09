### 解题思路
此处撰写解题思路

### 代码

```c
int strStr(char * haystack, char * needle){
    int i, j, k;
    int notExist = -1;

    if (needle == NULL || needle[0] == '\0') {
        return 0;
    }
    if (haystack == NULL || needle[0] == '\0') {
        return notExist;
    }

    for (i = 0; haystack[i] != '\0'; i++) {
        if (haystack[i] == needle[0]) {
            j = i;
            k = 0;
            while (haystack[j++] == needle[k++]) {
                if (needle[k] == '\0') {
                    return i;
                }
                if (haystack[j] == '\0') {
                    return notExist;
                }
            }
        }
    }

    return notExist;
}
```