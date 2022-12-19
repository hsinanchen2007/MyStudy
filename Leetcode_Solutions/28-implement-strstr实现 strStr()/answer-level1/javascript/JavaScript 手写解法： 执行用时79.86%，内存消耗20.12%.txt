```javascript []
var strStr = function(haystack, needle) {
    if (!needle) return ""
    outer: for (let i = 0; i < haystack.length; i++) {
        inner: for (let j = 0; j < needle.length; j++) {
            if (i + j > haystack.length - 1) return -1
            if (haystack[i + j] === needle[j]) {
                if (i + j < haystack.length && j === needle.length - 1) {
                    return i
                }
                continue inner;
            }
            continue outer;
        }
    }
    return -1
};
```

这里使用了两个指针，非贪婪算法。
如果针对needle的指针(j)到达了末尾，就认为匹配成功，返回针对haystack的指针(i)。




