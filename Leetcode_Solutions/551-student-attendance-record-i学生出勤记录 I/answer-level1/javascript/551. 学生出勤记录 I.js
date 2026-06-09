### 解题思路

利用正则表达式匹配字符串

### 代码

```javascript
/**
 * @param {string} s
 * @return {boolean}
 */
var checkRecord = function(s) {
    return !/(A.*A.*|LLL)/.test(s)
};
```