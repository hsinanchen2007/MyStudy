### 解题思路
![image.png](https://pic.leetcode-cn.com/d5bb97be9f37bdfb9cc012bb5bdd9b657e9371b29e3c1f769c8abc726c623d97-image.png)


### 代码

```javascript
/**
 * @param {number} N
 * @return {number}
 */
var fib = function (N) {
    let dp = new Array(N);

    dp[0] = 0;
    dp[1] = 1;

    if (N <= 1) return dp[N];

    for (let i = 2; i <= N; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[N];
};
```