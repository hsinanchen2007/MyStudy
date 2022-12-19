### 解题思路
注意使用memcmp
滑动窗口
### 代码

```c
int strStr(char * haystack, char * needle){
    if ((needle == NULL) || (haystack == NULL)){
        return 0;
    }

    int index = -1;
    int needleLength = strlen(needle);
    int haystackLength = strlen(haystack);
    for (int i = 0; i < haystackLength - needleLength + 1; i++) {
        if (memcmp(haystack + i, needle, needleLength) == 0) {
            index = i;
            break;
        }
    }
    return index;
}
```