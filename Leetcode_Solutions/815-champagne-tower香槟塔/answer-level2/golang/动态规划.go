### 解题思路

按照塔的方式构造金字塔二位数组，当前位置的杯数大于1，那么会被均分到下一行的两个杯子中，所以 dp[i+1][j] += (dp[i][j] - 1) / 2.0 以及 dp[i+1][j+1] += (dp[i][j] - 1) / 2.0

### 代码

```golang
func champagneTower(poured int, query_row int, query_glass int) float64 {
    dp := make([][]float64, query_row + 2)
    for i := 0; i < query_row + 2; i++ {
        dp[i] = make([]float64, i + 1)
    }
    dp[0][0] = float64(poured)
    for i := 0; i <= query_row; i++ {
        for j := 0; j <= i; j++ {
            if dp[i][j] > 1 {
                dp[i + 1][j] += (dp[i][j] - 1) / 2.0
                dp[i + 1][j + 1] += (dp[i][j] - 1) / 2.0
            }
        }
    }
    return minFloat(1.0, dp[query_row][query_glass])
}

func minFloat(a, b float64) float64 {
    if a < b {
        return a
    }
    return b
}
```