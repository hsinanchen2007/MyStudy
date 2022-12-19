### 解题思路
有跟我一样是求以2为底的对数的吗

### 代码

```javascript
/**
 * @param {number} n
 * @return {boolean}
 */
var isPowerOfTwo = function(n) {
    if(n === 0) return false
    const power = Math.log2(n)
    return Number.isInteger(power)?true:false
};
```