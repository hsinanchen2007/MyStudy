### 解题思路
此处撰写解题思路

### 代码

```golang
func maxAreaOfIsland(grid [][]int) int {
    if len(grid) == 0 {
        return 0
    }
    res := 0
    for i := 0; i < len(grid); i++ {
        for j := 0; j < len(grid[0]); j++ {
            curRes := dfs(i, j, grid)
            if res < curRes {
                res = curRes
            }
        }
    }

    return res
}

func dfs(i int, j int, grid [][]int) int {
    if i < 0 || j < 0 || i >= len(grid) || j >= len(grid[0]) || grid[i][j] == 0 {
        return 0
    }
    grid[i][j] = 0
    num := 1
    num = num + dfs(i - 1, j, grid)
    num = num + dfs(i, j + 1, grid)
    num = num + dfs(i + 1, j, grid)
    num = num + dfs(i, j - 1, grid)

    return num
}
```