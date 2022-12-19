### 解题思路
dp[i][0] = max(dp[i-1][0], dp[i-1][1]) dp[i][1] = dp[i-1][0] + nums[i]
dp[0][0], dp[0][1] = 0, nums[0]
### 代码

```golang
func rob(nums []int) int {
    n := len(nums)
    if n == 0 {
        return 0
    }
    if n == 1 {
        return nums[0]
    }
    dp := makeArray(n, 2)
    dp[0][0], dp[0][1] = 0, nums[0]
    for i := 1; i < len(nums); i ++ {
        dp[i][0] = max(dp[i-1][0], dp[i-1][1])
        dp[i][1] = dp[i-1][0] + nums[i]
    }
    return max(dp[n-1][0], dp[n-1][1])
}
func makeArray(m, n int)[][]int {
    dp := make([][]int, m)
    for i := 0; i < m; i ++ {
        dp[i] = make([]int, n)
    }
    return dp
}

func max(a, b int) int {
    if a < b {
        return b
    } else {
        return a
    }
}
```