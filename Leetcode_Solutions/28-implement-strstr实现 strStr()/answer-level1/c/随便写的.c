执行用时 :4 ms, 在所有 C 提交中击败了91.82%的用户
内存消耗 :7.2 MB, 在所有 C 提交中击败了83.63%的用户
```
int strStr(char * haystack, char * needle){
    if (strcmp(needle, "") == 0) {
        return 0;
    }
    int count1 = strlen(haystack);
    int count2 = strlen(needle);
    for (int i = 0; i < count1; i++) {
        for (int j = 0; j < count2; j++) {
            if (*(haystack+i+j) == *(needle+j)) {
                if (j == count2 - 1) {
                    return i;
                } else {
                    if (i + count2 > count1) {
                        return -1;
                    } else {
                        continue;
                    }
                }
            } else {
                break;
            }
        }
    }
    
    return -1;
}
```
