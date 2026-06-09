dp， 好像还可以滑动窗口
```
func numberOfArithmeticSlices(A []int) int {
    if len(A) <= 2 {
        return 0
    }
    dp := make([]int, len(A))
    dp[0] = 0
    dp[1] = 0
    sum := 0
    for i:=2;i<len(A);i++ {
        if A[i] - A[i-1] == A[i-1] - A[i-2] {
            dp[i] = dp[i-1] + 1
            sum += dp[i]
        }
    }
    return sum
}
```
