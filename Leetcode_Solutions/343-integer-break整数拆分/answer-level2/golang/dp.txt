### 解题思路
此处撰写解题思路

### 代码

```golang
func integerBreak(n int) int { 
    if n == 1 {
        return 0
    }
    if n == 2 {
        return 1
    }
    dp := make([]int, n+1)
    dp[1] = 1
    dp[2] = 1
    for i := 3; i <= n; i++ {
        
        for j:=1; j <= i/2; j++ {
            x := max(dp[j], j) 
            y := max(dp[i-j], i-j) 
            dp[i] = max(dp[i], x*y)
        }
    }

    return dp[n]
}

func max(i,j int)int {
    if i > j {
        return i
    }
    return j
}

```