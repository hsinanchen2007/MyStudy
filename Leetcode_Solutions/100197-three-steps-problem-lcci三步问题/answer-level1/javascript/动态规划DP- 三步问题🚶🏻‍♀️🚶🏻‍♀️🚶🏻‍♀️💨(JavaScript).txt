### 解题思路
注意到n的范围在[1, 1000000]之间，故使用**动态规划DP**（Dynamic programming）
第n层楼梯的**状态转移方程**为 dp[n] = (dp[n-3] + dp[n-2] + dp[n-1])%(1e9+7)
🚶🏻‍♀️🚶🏻‍♀️🚶🏻‍♀️💨

### 代码

```javascript
var waysToStep = function(n) {
    let m = 1e9+7
    let dp = [0,1,2,4]
    for(let i = 4; i<n+1; i++){
        dp[i] = (dp[i-1] + dp[i-2] + dp[i-3])%m
    }
    return dp[n]
};
```