### 解题思路
3的x次方 = n    两边同时取常用对数log10   x = log10(n)/log10(3)

### 代码

```javascript
/**
 * @param {number} n
 * @return {boolean}
 */
var isPowerOfThree = function(n) {
    const power = Math.log10(n)/Math.log10(3)
    return Number.isInteger(power)
};
```