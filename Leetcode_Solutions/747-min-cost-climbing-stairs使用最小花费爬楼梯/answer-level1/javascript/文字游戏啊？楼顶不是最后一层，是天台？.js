### 解题思路

搞我心态哦

### 代码

```javascript
/**
 * @param {number[]} cost
 * @return {number}
 */
// v[i]
// dp[i] = Math.min(dp[i-1] + v[i], dp[i-2] + v[i])

var minCostClimbingStairs = function(cost) {
    let dp = [cost[0], cost[1]]

    for(let i = 2; i< cost.length; i++){
        dp[i] = Math.min(dp[i-1], dp[i-2]) + cost[i]
    }
    // 文字游戏？？不是到倒数第一层，而是上天台？？？
    return Math.min(dp[cost.length - 2], dp[cost.length -1])
};
```