1.递归
```
func rob(nums []int) int {
    if len(nums) == 0 {
        return 0
    }
    //terminator
    if len(nums) == 1 {
        return nums[0]
    }

    //process logic of current level
    //drill down
    pre := rob(nums[:len(nums)-1])
    prePre := rob(nums[:len(nums)-2])

    return max(pre, prePre + nums[len(nums)-1])
}

func max(a, b int) int {
    if a>b {
        return a
    }
    return b
}
```
2.动态规划
```
func rob(nums []int) int {
    if len(nums) == 0 {
        return 0
    }

    dp := make([]int, len(nums)+1)
    dp[0], dp[1] = 0, nums[0]
    for i:=2; i<len(nums)+1; i++ {
        dp[i] = max(dp[i-1], dp[i-2]+nums[i-1])
    }
    return dp[len(nums)]
}

func max(a, b int) int {
    if a>b {
        return a
    }
    return b
}
```
