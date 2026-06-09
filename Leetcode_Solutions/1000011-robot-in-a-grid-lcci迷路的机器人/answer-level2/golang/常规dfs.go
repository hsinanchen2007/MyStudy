### 解题思路
可能有多个解，取其中一个就行；对于一个位置(r, c)如果已经访问过，再次访问可直接返回

### 代码

```golang
func pathWithObstacles(obstacleGrid [][]int) [][]int {
    if len(obstacleGrid) == 0 || len(obstacleGrid[0]) == 0 {
        return nil
    }
    m, n := len(obstacleGrid), len(obstacleGrid[0])
    var result [][]int
    visited := make([][]bool, m)
    for i := range visited {
        visited[i] = make([]bool, n)
    }
    var dfs func(r, c int) bool
    dfs = func(r, c int) bool {
        if r == m || c == n || obstacleGrid[r][c] == 1 || visited[r][c] {
            return false
        }
        visited[r][c] = true
        result = append(result, []int{r, c})
        if r == m-1 && c == n-1 {
            return true
        }
        if dfs(r+1, c) || dfs(r, c+1) {
            return true
        }
        result = result[:len(result)-1]
        return false
    }
    _ = dfs(0, 0)
    return result
}
```