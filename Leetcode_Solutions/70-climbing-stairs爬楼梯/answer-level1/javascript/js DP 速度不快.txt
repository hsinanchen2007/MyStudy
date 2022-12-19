### 解题思路
![image.png](https://pic.leetcode-cn.com/b741dcd302241835525eee4c92a25d74f8bdb16af616dd2074bea2840ed82c74-image.png)


### 代码

```javascript
/**
 * @param {number} n
 * @return {number}
 */
var climbStairs = function(n) {
    let dp = [];
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;

    for (let i = 3; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
};
```