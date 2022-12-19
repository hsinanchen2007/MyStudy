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
    if (!needle) return 0;
    var len = haystack.length;
    for (var i = 0; i < len; i++) {
        var l = i;
        var j = 0;
        while(j < needle.length && haystack[l] === needle[j]) {
            l++;
            j++;
        }

        if (j === needle.length) {
            return i;
        }
    }

    return -1;
};
```