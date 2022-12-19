```
1. 暴力法
func maxSubArray(nums []int) int {
    maxSum := nums[0]
    for i:=0; i < len(nums); i++ {
        sum :=0
        for j:=i; j< len(nums); j++ {
            sum += nums[j]
            if sum > maxSum {
                maxSum = sum
            }
        }
    }
    return maxSum
}
2. 动态规划
// 状态转移方程 dp[i] = max{dp[i-1]+nums[i], nums[i]}
func maxSubArray(nums []int) int {
    dp := make([]int, len(nums))
    dp[0] = nums[0]
    res := nums[0]
    for i:=1; i<len(nums); i++ {
        dp[i] = max(dp[i-1] + nums[i], nums[i])
        res = max(res, dp[i])
    }
    return res
}
```
