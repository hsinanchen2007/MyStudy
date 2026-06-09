### 解题思路
数学方法，求得最大公约数。

### 代码

```javascript
/**
 * @param {number} x
 * @param {number} y
 * @param {number} z
 * @return {boolean}
 */
var canMeasureWater = function(x, y, z) {
    if (x + y < z) {
        return false;
    }
    if (x === 0 || y === 0) {
        return (z === 0) || (x + y  === z);
    }
    return (z % gcd(x, y)) === 0;
};
function gcd(a, b) {
    if (b === 0) {
        return a;
    }
    return gcd(b, a % b);
}
```