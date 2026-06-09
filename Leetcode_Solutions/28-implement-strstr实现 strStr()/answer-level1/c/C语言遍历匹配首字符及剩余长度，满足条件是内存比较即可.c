遍历haystack匹配needle的首字符并比较剩余长度，不符合则continue；
一旦匹配到首字符且剩余长度满足预期，则直接比较内存中的信息，一致则返回下标。

![image.png](https://pic.leetcode-cn.com/6c69a517e47231aaa9b0eaa1d24b6175a4b6c7484df7351d027ba2a55ff2e65d-image.png)


```
int strStr(char * haystack, char * needle){
    int i, j, iRet;
    int strLen1 = strlen(haystack);
    int strLen2 = strlen(needle);

    if (needle == NULL || strLen2 == 0) {
        return 0;
    }

    if (haystack == NULL || strLen1 == 0) {
        return -1;
    }

    for (i = 0; i < strLen1; i++) {
        if (haystack[i] != needle[0] || ((strLen1 - i) < strLen2)) {
            continue;
        }

        iRet = memcmp(haystack + i, needle, strLen2);
        if (iRet == 0) {
            return i;
        }
    }

    return -1;
}
```

