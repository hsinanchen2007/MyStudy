### 解题思路
$dp[i]$ 为组成i的平方数个数最小值
$dp[i-j^2]$ 为组成比i少一个平方数的最小值
因此 $dp[i] = dp[i-j^2]+1$
$dp[i]最大值为i个1$

### 代码

```golang
func numSquares(n int) int {
    dp := make([]int, n+1)
    for i := 1; i <= n; i++ {
        dp[i] = i
        for j := 1; i - j * j >= 0; j++ {
            if dp[i - j * j] + 1 < dp[i] {
                dp[i] = dp[i - j * j] + 1
            }
        }
    }
    return dp[n]
}
```