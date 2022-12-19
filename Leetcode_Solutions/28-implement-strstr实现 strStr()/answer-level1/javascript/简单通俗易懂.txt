### 解题思路

1.把needle在haystack循环过一遍

循环长度就是 haystack - needle + 1

2.把满足needle长度的每个字符串轮流取出比较

满足即返回指针

3.最后啥也没匹配到

返回-1

### 代码

```javascript
/**
 * @param {string} haystack
 * @param {string} needle
 * @return {number}
 */
var strStr = function(haystack, needle) {
    let len1 = haystack.length;
    let len2 = needle.length
    for (let i = 0; i < len1 - len2 + 1; i++) {
        if (haystack.substring(i, i + len2) === needle) {
            return i;
        }
    }
    return -1;
};
```