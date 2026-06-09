### 解题思路
裴蜀定理: 对于任意整数x, y，一定存在整数a，b，使得ax+by一定是Gcd(x,y)的倍数。
所以本题转化为求z是是否是x，y的最大公约数的倍数
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
    if (x === 0) return y === z;
    if (y === 0) return x === z;
    const Gcd = (a, b) => {
        let min = a < b ? a : b;
        while(min) {
            if(a % min === 0 && b % min ===0) return min;
            min--;
        }
        return 1;
    };
    return z % Gcd(x, y)=== 0;
};
```