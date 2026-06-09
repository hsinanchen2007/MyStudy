### 解题思路
dp[i][0], dp[i][1] 分别表示截止到i不偷取nums[i]的最大收益和截止到i偷取nums[i]的最大收益
加上的限制是能偷取nums[0]处就不能偷取nums[len-1]处，反之亦然，所以可以分为两个问题分别dp，再取两者之大即可

### 代码

```golang
func rob(nums []int) int {
    n := len(nums)
    if n == 0 {
        return 0
    } else if n == 1 {
        return nums[0]
    }
    return max(getMax(nums[0:n-1]), getMax(nums[1:n]))
}

func getMax(nums []int) int {
    n := len(nums)
    dp := makeArray(n, 2)
    dp[0][0], dp[0][1] = 0, nums[0]
    for i := 1; i < n; i++ {
        dp[i][0] = max(dp[i-1][0], dp[i-1][1])
        dp[i][1] = dp[i-1][0] + nums[i]
    }
    result := max(dp[n-1][0], dp[n-1][1])
    return result
}

func makeArray(m, n int)[][]int {
    dp := make([][]int, m)
    for i := 0; i < m; i++ {
        dp[i] = make([]int, n)
    }
    return dp
}

func max(nums ...int) int {
    tmp := make([]int, len(nums))
    for i, v := range nums {
        tmp[i] = v
    }
    sort.Ints(tmp)
    return tmp[len(nums)-1]
}
```