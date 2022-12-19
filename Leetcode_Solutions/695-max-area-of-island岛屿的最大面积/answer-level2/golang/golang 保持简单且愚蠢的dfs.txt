### 代码

```golang
/**
1. 由于岛屿的形状不确定 所以只能用回溯法搜索解空格
2. 这里定义的dfs为计算一个岛屿的面积
3. 通过保存全局最大面积求得解
4. 通过将遍历过的点修改为0解决重复遍历的问题
*/
func maxAreaOfIsland(grid [][]int) int {
    if len(grid) == 0{
        return 0
    }
    m, n := len(grid), len(grid[0])
    res := 0
    for i:=0;i<m;i++{
        for j:=0;j<n;j++{
            if grid[i][j] == 1{
                res = max(res,dfs(grid,i,j))
            }      
        }
    }
    return res
}
func dfs(grid [][]int,i,j int)int{
    res := 1
    grid[i][j] = 0
    
    if i > 0 && grid[i-1][j] == 1{
        res += dfs(grid,i-1,j)
    }
    if i < len(grid)-1 && grid[i+1][j] == 1{
        res += dfs(grid,i+1,j)
    }
    if j > 0 && grid[i][j-1] == 1{
        res += dfs(grid,i,j-1)
    }
    if j < len(grid[0])-1 && grid[i][j+1] == 1{
        res += dfs(grid,i,j+1)
    }
    return res
}
func max(a,b int)int{
    if a > b{
        return a
    }
    return b
}
```