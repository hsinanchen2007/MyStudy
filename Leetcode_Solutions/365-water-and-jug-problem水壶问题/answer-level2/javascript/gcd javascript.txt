### 解题思路
gcd

### 代码

```javascript
/**
 * @param {number} x
 * @param {number} y
 * @param {number} z
 * @return {boolean}
 */
let gcd = (a, b) => {
    return b == 0 ? a : gcd(b, a % b) 
}
var canMeasureWater = function(x, y, z) {
    if(z == 0) return true
    if (x + y < z) return false
    if (x == 0 || y == 0) return (x + y) == z
    
    return z % gcd(y, x) == 0
};

```