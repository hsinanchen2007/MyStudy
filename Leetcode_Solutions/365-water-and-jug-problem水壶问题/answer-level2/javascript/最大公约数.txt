### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number} x
 * @param {number} y
 * @param {number} z
 * @return {boolean}
 */
var canMeasureWater = function(x, y, z) {
    if (x + y < z) return false;
    if (z === 0) return true;
    function gcd(a, b) {
        if (b===0) return a;
        return gcd(b, a%b);
    }
    return z % gcd(x, y)  === 0
};
```