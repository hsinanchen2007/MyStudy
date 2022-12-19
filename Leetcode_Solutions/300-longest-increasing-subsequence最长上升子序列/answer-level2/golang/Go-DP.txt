```
func lengthOfLIS(nums []int) int {
    if len(nums) < 2 {
        return len(nums)
    }
    dp := make([]int, len(nums))
    max := 1
    for i:=0;i<len(dp);i++{
        dp[i] = 1
    }
    for i:=1;i<len(nums);i++{
        for j:=0;j<i;j++{
            if nums[i] > nums[j]{
                dp[i] = Max(dp[i], dp[j] + 1)
            }
        }
        if dp[i] > max {
            max = dp[i]
        }
    }
    return max
}

func Max(a, b int) int{
    if a > b {
        return a
    }
    return b
}
```
