
dp，双百，时间复杂度O(n) 空间复杂度O(1)

### 代码

```golang
func massage(nums []int) int {
    if len(nums) == 0 {
        return 0
    } else if len(nums) == 1 {
        return nums[0]
    }
    dp := [2]int{}
    dp[0], dp[1] = nums[0], max(nums[0], nums[1])
    for i:=2; i<len(nums); i++ {
        dp[0], dp[1] = dp[1], max(nums[i]+dp[0], dp[1])
    }
    return dp[1]
}

func max(a, b int) int {
    if a>b {
        return a
    }
    return b
}
```