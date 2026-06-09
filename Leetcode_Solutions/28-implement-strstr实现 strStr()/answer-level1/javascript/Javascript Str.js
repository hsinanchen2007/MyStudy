### 解题思路
直接解法

### 代码

```javascript
/**
 * @param {string} haystack
 * @param {string} needle
 * @return {number}
 */
var strStr = function(haystack, needle) {
    // 如果needle为空直接返回0
    if (!needle) return 0
    let needleLen = needle.length
    let haystackLen = haystack.length
    let endIndex = haystackLen - needleLen
    // 如果needle长度超过haystack直接返回-1
    if (endIndex < 0) return -1
    // 如果长度相等，直接判断是否相等
    if (endIndex === 0) return (haystack === needle) ? 0 : -1
    let temp
    // 长度不等，就循环取needle长度来比较
    for (let i = 0; i <= endIndex; i++) {
        temp = haystack.substr(i, needleLen)
        if (temp === needle) return i
    }
    return -1
};
```