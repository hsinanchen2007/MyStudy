
```golang
func rob(nums []int) int {
    if len(nums) == 0  {
        return 0
    }

    dp := make([]int, len(nums))
    result := 0

    for i:=0; i < len(nums); i++ {
        dp[i] = nums[i]
        for j:=0; j <=i-2; j++ {
            dp[i] = max(dp[i], dp[j]+nums[i])
        }

        result = max(result, dp[i])
    }
    
    return result
}

func max(i, j int) int {
    if i > j {
        return i
    }
    return j
}

// dp[i] = max(dp[j]+nums[i], dp[i]), j:0~i-2
```