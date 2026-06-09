### 解题思路
此处撰写解题思路

### 代码

```golang
func generateParenthesis(n int) []string {
    dp := make([][]string,n+1)
    dp[0] = []string{""}
    dp[1] = []string{"()"}
    for i := 2; i < n+1; i++{
        for j := 0;j < i; j++{
            for x := range dp[j]{
                for y := range dp[i-1-j]{
                    res := "("+dp[j][x]+")"+dp[i-1-j][y]
                    dp[i] = append(dp[i],res)
                }
            }
            
        }
    }
    return dp[n]
}
```