![2019-09-28_20-22.png](https://pic.leetcode-cn.com/c64b0c6567cb894a3f3cd84be846f7fa0f4fee771d3544e3a48ce4a62fd54692-2019-09-28_20-22.png)

```c
int strStr(char * haystack, char * needle){
    // needle 是空字符串，认为所有字符串都包含空字符串，索引为 0
    if (*needle == 0) return 0;
    // haystack 是空字符串，认为它不包含任何字符串（空字符串除外）
    if (*haystack == 0) return -1;
    
    // 标记 haystack 的头指针
    char * head = haystack;
    // 扫描偏移
    int offset;
    // 遍历 haystack 的子串
    while (*haystack) {
        offset = 0;
        while (1) {
            // 到达 needle 末尾，认为能匹配上
            if (needle[offset] == 0) return haystack - head;
            // 到达 haystack 末尾，认为没有匹配
            if (haystack[offset] == 0) return -1;
            // 不相等则跳出本次循环
            if (haystack[offset] != needle[offset]) break;
            offset++;
        }
        // 移动到下个子串
        haystack++;
    }
    return -1;
}
```
