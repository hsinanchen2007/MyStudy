### 解题思路
优雅无比的js解法，可惜是看了答案写的（https://leetcode-cn.com/problems/water-and-jug-problem/solution/cyu-yan-shu-xue-jie-fa-tai-xiu-liao-dai-ma-jian-ji/）

![image.png](https://pic.leetcode-cn.com/90ae0ed83f2c1c0060fa311385eab626094d3d3093768a16349d9c6023565a08-image.png)


### 代码

```javascript
// To find the greatest common divisor
const gcd = (a, b) => {
    return (!b) ? a : gcd(b, a % b);
}

/**
 * @param {number} x
 * @param {number} y
 * @param {number} z
 * @return {boolean}
 */
var canMeasureWater = function (x, y, z) {
    if (z > x + y) return false;
    return z === 0 ? true : (z % gcd(x, y) === 0);
};
```