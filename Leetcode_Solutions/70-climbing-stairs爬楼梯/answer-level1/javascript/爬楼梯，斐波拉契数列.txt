### 解题思路
动态规划

到第N阶相当于是到(n - 1)阶后向上爬1阶  和到(n - 2)阶后向上爬2阶

所以到达第N阶的方法总数就是到第(i−1) 阶和第 (i−2) 阶的方法数之和。

就是一个斐波拉契数列

### 代码

```javascript
/**
 * @param {number} n
 * @return {number}
 */
var climbStairs = function(n) {
    if (n < 4) return n;
    let b1 = 2;
    let b2 = 3;
    let sum = 5;
    for (let i = 4; i <= n; i++) {
        sum = b1 + b2;
        b1 = b2;
        b2 = sum;
    }
    return sum;
};
```