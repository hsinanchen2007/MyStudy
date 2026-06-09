### 解题思路
1. dp 数组代表 当前[i][j]处 构成的最大矩形面积时的边长
2. 当此处为1时 dp[i][j] = min(dp[i-1][j],dp[i][j-1],dp[i-1][j-1])+1
3. 初始化时全为0 加入哨兵技巧可以简化边界处理

### 代码

```golang
func maximalSquare(matrix [][]byte) int {
    if len(matrix) == 0{
        return 0
    }
    m, n,res := len(matrix), len(matrix[0]), 0
    dp := make([][]int,m+1)
    for i:=0;i<m+1;i++{
        dp[i] = make([]int,n+1)
    }
    for i:=1;i<m+1;i++{
        for j:=1;j<n+1;j++{
            if matrix[i-1][j-1] == '1'{
                dp[i][j] = min(dp[i-1][j],dp[i][j-1],dp[i-1][j-1])+1
                res = max(res,dp[i][j] * dp[i][j])
            }
        }
    }
    return res
}
func min(a,b,c int)int{
    if a > b{
        if b < c{
            return b
        }
        return c
    }else{
        if a < c{
            return a
        }
        return c
    }
}
func max(a, b int)int{
    if a > b{
        return a
    }
    return b
}
```