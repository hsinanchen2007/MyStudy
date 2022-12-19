
### 代码

```golang
const U int = 0
const D int = 1
const L int = 2
const R int = 3
func maxAreaOfIsland(grid [][]int) int {
    if len(grid) == 0 || len(grid[0]) == 0 {return 0}
    ret := 0
    var m, n int = len(grid), len(grid[0])

    for i:=0;i<m;i++{
        for j:=0;j<n;j++{
            if grid[i][j] == 0 {continue}
            tmp_ret := dfs(grid, i, j, m, n)
            if tmp_ret > ret{ret = tmp_ret}
        }
    }
    return ret
}

func dfs(grid [][]int, i int, j int, m int, n int) int {
    DIR := [4]int{-1, 1, -1, 1}
    if !ensureValid(i, j, m, n){return 0}
    var ret int
    if grid[i][j] == 0 {
        return ret
    } else {
        ret += 1
        grid[i][j] = 0
        return ret + dfs(grid, i + DIR[U], j, m, n) + dfs(grid, i + DIR[D], j, m, n) + dfs(grid, i, j+DIR[L], m, n) + dfs(grid, i, j+DIR[R], m, n)
    }
}

func ensureValid( i, j, m, n int) bool {
    if i < 0 || i > m-1{
        return false
    } else if j < 0 || j>n-1 {
        return false
    } else {
        return true
    }
}
```