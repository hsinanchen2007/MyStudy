### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {string} haystack
 * @param {string} needle
 * @return {number}
 */
var strStr = function(haystack, needle) {
      var orignLen = haystack.length
    var targetLen = needle.length
    var len = orignLen - targetLen
    var i = 0
    while (i <= len) {
      if (haystack.slice(i, i+targetLen) == needle) {
        return i
      }
      i = i + 1
    }
    return -1
};
```