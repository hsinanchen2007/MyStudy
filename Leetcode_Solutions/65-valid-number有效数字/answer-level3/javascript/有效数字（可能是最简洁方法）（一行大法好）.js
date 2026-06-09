### 解题思路
执行用时 : 84 ms, 在所有 JavaScript 提交中击败了95.96%的用户
内存消耗 : 36.3 MB, 在所有 JavaScript 提交中击败了87.50%的用户

任何数字运算均可得到数字
### 代码

```javascript
/**
 * @param {string} s
 * @return {boolean}
 */
var isNumber = function(s) {
    return !Number.isNaN(s.trim().length ? s - 0 : NaN)
};
```