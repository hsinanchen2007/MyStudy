### 解题思路
根据题意，去除前后空格，再用split,重点是正则/\s+/,然后再转回去就是了

### 代码

```javascript
/**
 * @param {string} s
 * @return {string}
 */
var reverseWords = function(s) {
    return s.trim().split(/\s+/).reverse().join(' ').trim()
};
```