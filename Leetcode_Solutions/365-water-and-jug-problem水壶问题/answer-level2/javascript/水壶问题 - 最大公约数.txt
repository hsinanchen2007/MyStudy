### 解题思路
# 求最大公约数
### 代码

```javascript
/**
 * @param {number} x
 * @param {number} y
 * @param {number} z
 * @return {boolean}
 */

/**
 * 最大公约数：
 * 根据条件可得出：     ax+by=z 
 * 又因为a,b为整数：    x + y >= z 才能满足以上条件
 */
var canMeasureWater = function(x, y, z) {
    if (x + y < z) return false;
    if( x == 0 || y == 0 ) return z == 0 || x + y == z
    let gcd = 0 , i = 0
    while( i < x || i < y ){
        i++
        if( x % i == 0 && y % i == 0 ) gcd = i
    }
    return z % gcd == 0
};
```