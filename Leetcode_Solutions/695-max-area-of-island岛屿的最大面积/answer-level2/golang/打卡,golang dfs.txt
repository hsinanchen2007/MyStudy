### 解题思路
dfs

### 代码

```golang
func maxAreaOfIsland(grid [][]int) int {
    ans := 0
    for i:=0;i<len(grid);i++ {
        for j:=0;j<len(grid[0]);j++{
            if grid[i][j] == 1 {
                ans = Max(ans,dfs(i,j,grid))
            }
        }
    }
    return ans
}

func dfs(i,j int,grid [][]int) int {
    if i < 0 || j < 0 || i == len(grid) || j == len(grid[0]) || grid[i][j] == 0 {
        return 0
    }
    grid[i][j] = 0
    num := 1
    num += dfs(i-1,j,grid)
    num += dfs(i+1,j,grid)
    num += dfs(i,j-1,grid)
    num += dfs(i,j+1,grid)
    return num
}

func Max(a,b int) int {
    if a>b{
        return a
    }
    return b
}
```