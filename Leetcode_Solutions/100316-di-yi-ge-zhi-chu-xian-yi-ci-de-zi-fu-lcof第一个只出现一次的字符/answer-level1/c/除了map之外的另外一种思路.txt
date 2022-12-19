### 解题思路
1 从左向右遍历。左侧遍历到a，用右侧指针b指向a+1遍历到结尾，如果有重复把a节点的字符串放到一个重复数组里面同时a++
2 右侧指针b遍历到结尾的时候，有两种情况，第一种重复数组里面没有a节点的字符，那么这个是要找的结果。如果有，那么a+1.继续遍历。直至a到字符串结尾


### 代码

```c
char firstUniqChar(char* s){
  long strLength = strlen(s);
    if (s == NULL || strLength == 0) {
        return ' ';
    }
    long repeatCount = 0;
    char *repeatStrs = malloc(sizeof(char) *(strLength+1));
    memset(repeatStrs, 0, sizeof(char) *(strLength+1));
    long start = 0, end =0;
    while (start < strLength) {
        end = start+1;
        while (end < strLength) {
            if (s[end] == s[start]) {
                repeatStrs[repeatCount++] = s[start];
                start++;
                break;
            }
            else {
                end++;
            }
        }
        
        if (end >= strLength && start < strLength) {
            bool isRepeatedChar = false;
            for (int i = 0; i < repeatCount; i++) {
                if (repeatStrs[i] == s[start]) {
                    isRepeatedChar = true;
                    start++;
                    break;
                }
            }
            if (!isRepeatedChar) {
                char theChar = s[start];
                free(repeatStrs);
                return theChar;
            }
        }
    }
    return ' ';
}
```