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
    if(!needle) return 0;
    return haystack.indexOf(needle);
};
```