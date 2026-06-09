### 解题思路

其实这是一道脑筋急转弯，看了下还有挺多公司考的，以下是具体思路：
- 如果两个字符串相等，那么不存在最长特殊序列，返回 ``-1``
- 否则，返回最长的字符串的长度（此时互不为子序列）

### 代码

```javascript
/**
 * @param {string} a
 * @param {string} b
 * @return {number}
 */
var findLUSlength = function(a, b) {
    if (a === b) {
        return -1
    }
    return Math.max(a.length, b.length)
};
```