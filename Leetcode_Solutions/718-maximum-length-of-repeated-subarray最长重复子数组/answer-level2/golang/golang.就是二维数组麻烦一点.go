### 解题思路
需要先初始化二维数组。然后就是典型的二维DP依次检查，拿到结果 判断最大值

### 代码

```golang
func findLength(A []int, B []int) int {
    if len(A) <= 0 || len(B) <= 0 {
        return 0
    }
    dp := make([][]int, len(A) + 1)
    for i := 0; i < len(A)+1;i++ {
        dp[i] = make([]int, len(B) + 1)
    }
    res := 0
    for i := 0; i < len(A); i++ {
        for j := 0; j < len(B); j++ {
            if A[i] == B[j] {
                dp[i+1][j+1] = dp[i][j] + 1
                res = max(res, dp[i+1][j+1])
            }
        }
    }
    return res
}

func max(a, b int) int {
    if a > b {
        return a
    }
    return b
}
```