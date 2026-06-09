### 解题思路
- 执行用时 :76 ms, 在所有 JavaScript 提交中击败了95.19%的用户
- 内存消耗 :36.1 MB, 在所有 JavaScript 提交中击败了62.13%的用户

### 代码

```javascript
/**
 * @param {number} x
 * @return {number}
 */
var reverse = function(x) {
    let num = (Math.abs(x) + '').split('').map((x) => x * 1).reverse().join('') * (x > 0 ? 1 : -1);
    return num > Math.pow(2, 31) - 1 || num < Math.pow(-2, 31) ? 0 : num;
};
```