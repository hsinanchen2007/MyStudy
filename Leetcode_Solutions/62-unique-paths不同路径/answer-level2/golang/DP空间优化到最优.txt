### 解题思路
一维数组做缓存 DP空间优化到最优

### 代码

```golang
// 空间优化到O(n), 同一行可以缓存全部数据
func uniquePaths(m int, n int) int {
     if m == 1 && n == 1 {
        return 1
    }
    var res []int
    // 初始化,第一行永远是1，第一列也永远是1，因为复用res，所以res[0]永远表示第一列，永远不变
    for i := 0; i < n; i++ {
        res = append(res, 1)
    }
    // 时间复杂度mxn不变
    for i := 1; i < m; i++ {
        for j := 1; j < n; j++ {
            res[j] += res[j - 1]
        }
    }
    return res[n - 1]
}
/*
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
}*/
```