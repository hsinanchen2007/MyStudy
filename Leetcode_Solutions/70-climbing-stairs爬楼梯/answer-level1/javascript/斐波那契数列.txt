### 解题思路
用 F[n] 表示当有 n 阶楼梯时的路线数。

F[n] = F[n-1] + F[n-2] (因为从第 n - 1 和 第 n - 2 阶都可以一步到达楼顶)

即：F[n] 是斐波那契数列的第 n - 1 项。

### 代码

```javascript
/**
 * @param {number} n
 * @return {number}
 */
var climbStairs = function(n) {
    if (n < 3) return n;
    let a = 1, b = 1;
    while (--n >= 0) {
        const c = b;
        b = a + b;
        a = c;
    }
    return a;
};
```