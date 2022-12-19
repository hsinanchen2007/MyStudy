- 动态规划
- 以0开头相当于 dp[n-]

``` golang
func countNumbersWithUniqueDigits(n int) int {
    return method_logic(n)
}

//n=2
//区分首位以0开始, 以0开始相当于dp[n-1]
//dp[0] = 1
//dp[1] = (dp[0] + 9) = 10
//dp[2] = dp[1]  +  9 * 9 =  dp[1] + 9 * A(9,1) =  91
//dp[3] = dp[2]  +  9 * 9 * 8 = dp[2] + 9 * A(9, 2) = 739
//dp[4] = dp[4]  +  9 * 9 * 8 * 7

//dp[0] = 1
//dp[1] = 10
//i >= 2 ==> dp[i] = dp[i-1] + 9 * A(9,i-1)
func method_logic(n int) int {
    if n == 0 {
        return 1
    }
    if n == 1 {
        return 10
    }

    dp := make([]int, n + 1)
    dp[1] = 10
    for i := 2; i <= n; i++ {
        dp[i] = dp[i-1] + 9 * math_a(9, i - 1)
    }

    return dp[n]
}

func math_a(a, b int) int {
    cnt := 1
    for i := 0; i < b; i++ {
        cnt *= a - i
    }
    return cnt
} 
```
