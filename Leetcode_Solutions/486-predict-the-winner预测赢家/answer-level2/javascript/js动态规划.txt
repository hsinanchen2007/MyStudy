dp[i][j] 表示如果数组为 i - j 范围，其能赢的分数（可以为正，也可以为负）。对于 dp[i][j] 我选择的情况会有两种：

- 选择 dp[i][i]，那我的对手会从剩下的 dp[i+1][j] 选择对他最有利的情况
- 选择 dp[j][j]，那我的对手会从剩下的 dp[i][j-1] 选择对他最有利的情况

因此我从 dp[i][j] 中选择对我最有利的方法时，能赢的分数为：(dp[i][i] - dp[i+1][j]) 和 (dp[j][j] - dp[i][j-1]) 中更大的一个。

```
var PredictTheWinner = function(nums) {
    var n = nums.length;
    if(n % 2 === 0) return true;
    
    var dp = [];
    for(var i = 0; i < n; i++){
        dp[i] = [];
        dp[i][i] = nums[i];
    }
    
    for(var l = 1; l < n; l++){
        for(var i = 0; i < n - l; i++){
            dp[i][i+l] = Math.max((dp[i][i] - dp[i+1][i+l]), (dp[i+l][i+l] - dp[i][i+l-1]));
        }
    }
    return dp[0][n-1] >= 0;
};
```
