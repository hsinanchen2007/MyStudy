### 解题思路
dp[i][j] = min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]) + 1 if matrix[i][j] == '1' else 0
其中dp[i][j]表示以matrix[i][j]为右下角形成的正方形的边长
### 代码

```golang
func maximalSquare(matrix [][]byte) int {
    rows := len(matrix)
    if rows == 0{
        return 0
    }
    cols := len(matrix[0])
    if cols == 0 {
        return 0
    }
    dp := makeArray(rows, cols)
    max := 0
    for i := 0; i < rows; i++ {
        if matrix[i][0] == '1' {
            dp[i][0], max = 1, 1
        }
    }
    for j := 0; j < cols; j++ {
        if matrix[0][j] == '1' {
            dp[0][j], max = 1, 1
        }
    }
    if rows == 1 || cols == 1 {
        return max
    }
    for i := 1; i < rows; i++ {
        for j := 1; j < cols; j++ {
                if matrix[i][j] == '1' {
                    dp[i][j] = min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]) + 1
                }
                if dp[i][j] > max {
                    max = dp[i][j]
                }
            }
        }
        return max * max
    }

func makeArray(rows, cols int) [][]int {
    m := make([][]int, rows)
    for i := 0; i < rows; i++ {
        m[i] = make([]int, cols)
    }
    return m
}

func min(a, b, c int) int {
    var tmp int
    if a > b {
        tmp = b
    } else {
        tmp = a
    }
    if tmp > c {
        return c
    } else {
        return tmp
    }
}
```