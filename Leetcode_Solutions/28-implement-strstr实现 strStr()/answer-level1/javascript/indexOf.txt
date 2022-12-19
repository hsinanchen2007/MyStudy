### 解题思路
indexOf刚好符合题目要求
当然 也可以用substr截取法暴力破取

### 代码

```javascript
/**
 * @param {string} haystack
 * @param {string} needle
 * @return {number}
 */
var strStr = function(haystack, needle) {
return haystack.indexOf(needle)
};
```