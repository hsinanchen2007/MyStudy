### 解题思路
没什么思路，正面刚

### 代码

```javascript
/**
 * @param {number} x
 * @return {number}
 */
var reverse = function(x) {
    let bit = x > 0 ? 1 : -1;
    let MAX = Math.pow(2, 31) - 1;
    let num = parseInt(String(Math.abs(x)).split('').reverse().join(''), 10);
    return num > MAX ? 0 : num * bit;
};
```