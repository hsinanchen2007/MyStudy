### 解题思路
- dp[nums...] == 1
- dp[i] = dp[i] + dp[i - nums...]

### 代码

```golang
func combinationSum4(nums []int, target int) int {
    return method_dp(nums, target)
}

/*
target...
    nums...
        i == j
            dp[i] + = 1
        i > j && dp[i-j] != 0
            dp[i] += dp[i-j]

return dp[target]
*/
func method_dp(nums []int, target int) int {
    dp := make([]int, target + 1)
    for i := 1; i <= target; i++ {
        for _, j := range nums {
            if i == j {
                dp[i] += 1
                continue
            }
            if i > j && dp[i-j] != 0 {
                dp[i] += dp[i-j]
            }
        }
    }
    return dp[target]
}
```