![1572954493967.jpg](https://pic.leetcode-cn.com/03e7e0d280abc6553720f401c36ce01b82a7556a3a3e54508c565b95b4a86370-1572954493967.jpg)

```
var strStr = function(haystack, needle) {
    const hLen = haystack.length
    const nLen = needle.length
    if (hLen < nLen) {
        return -1
    }
    if (hLen === nLen) {
        return haystack === needle ? 0 : -1
    }
    if (!hLen && nLen) {
        return -1
    }
    if (!nLen) {
        return 0
    }
    for (let i = 0; i < hLen - nLen + 1; i++) {
        if (haystack.substr(i, nLen) === needle) {
            return i
        }
    }
    return -1
};
```

