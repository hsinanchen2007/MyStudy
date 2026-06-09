### 解题思路
哈哈哈我又来了 求几的幂次方都可以
4的x次方=n 两边取常用对数 x = log10(n)/log10(4)

### 代码

```javascript
/**
 * @param {number} num
 * @return {boolean}
 */
var isPowerOfFour = function(num) {
    const power = Math.log10(num)/Math.log10(4)
    return Number.isInteger(power)
};
```