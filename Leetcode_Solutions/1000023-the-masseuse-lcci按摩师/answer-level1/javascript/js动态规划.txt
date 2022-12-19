### 动态规划

1. 设最后一个预约的最优解为dp[n]，因为不能相邻，所以得出状态转移方程为`dp[i] = Math.max(dp[i -1], dp[i - 2] + nums[i])`

2. 找出起始值，容易得出dp[0] = nums[0], dp[1] = Math.max(nums[0], nums[1])

3. 要注意corner case....没有预约的时候返回0

```
var massage = function(nums) {
    if (nums.length < 2) return nums[0] || 0
    const dp = [nums[0], Math.max(nums[0], nums[1])]
    for (let i = 2; i < nums.length; i++) {
        dp[i] = Math.max(dp[i -1], dp[i - 2] + nums[i])
    }
    return dp.pop()
};
```