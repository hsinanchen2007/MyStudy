### 解题思路
dp数组没有js直接Math.pow来的快

（第一个是直接 Math.pow的）
![image.png](https://pic.leetcode-cn.com/a939d0425d4173142addf184ed77e27f993e127d6414f40e5c666434fcb89812-image.png)

### 代码

```javascript
/**
 * @param {number} x
 * @param {number} n
 * @return {number}
 */
var myPow = function (x, n) {
    if (x === 1) {
        return 1;
    }
    if (n === 0) {
        return 1;
    }
    if (n < 0) {
        x = 1 / x;
        n = -1 * n;
    }
    if (x === -1) {
        if (n > 0 && (n & 1) === 0) {
            return 1;
        } else if (n > 0 && (n & 1) != 0) {
            return -1
        }
    }

    let dp = new Array(n + 1);
    dp[0] = 1;
    dp[1] = x;

    for (let i = 2; i <= n; i++) {
        if ((i & 1) === 0) {
            dp[i] = (dp[i / 2] * dp[i / 2]);
        } else {
            dp[i] = (dp[(i - 1) / 2] * dp[(i - 1) / 2] * x);
        }
        if (dp[i] === 0) return 0;
    }
    return dp[n];
};

```