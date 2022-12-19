### 解题思路
此处撰写解题思路

### 代码

```golang
func uniquePaths(m int, n int) int {
    if m == 1 && n == 1 {
        return 1
    }
    var res [][]int
    // 初始化
    for i := 0; i < m; i++ {
        var tmp []int
        for j := 0; j < n; j++ {
            tmp = append(tmp, 1)
        }
        res = append(res, tmp)
    }
    for i := 1; i < m; i++ {
        for j := 1; j < n; j++ {
            res[i][j] = res[i - 1][j] + res[i][j - 1]
        }
    }
    return res[m - 1][n - 1]
}
```