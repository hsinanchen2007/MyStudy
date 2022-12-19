### 解题思路
此处撰写解题思路
[[1,0,1],
[0,0,0],
[1,0,1]]

初始level 为1
先判断有没有陆海交界
如果有 res = level
dfs一圈 把紧挨陆地的海置为 level + 1
上例变为
[[2,2,2],
[2,0,2],
[2,2,2]]

如果之前有陆海交界
再扫一遍 直到把海填满

### 代码

```golang
func maxDistance(grid [][]int) int {
    
    res := -1
    haslevel := true;
    level := 1
    for haslevel {
        
        haslevel = false
        for i := 0; i< len(grid); i++ {
            for j := 0; j < len(grid); j++ {
                if i < len(grid)-1 && j<len(grid)-1 &&
                ( grid[i][j] != grid[i+1][j] || grid[i][j] != grid[i][j+1]) {
                    haslevel = true
                }else if i == len(grid) - 1&& j<len(grid)-1 &&
                (grid[i][j] != grid[i][j+1]){
                    haslevel = true
                }else if i < len(grid)-1 && j == len(grid) -1 &&
                (grid[i+1][j] != grid[i][j]){
                    haslevel = true
                }       
                if grid[i][j] == level && haslevel  {
                    dfs(grid, i, j, level)
                   
                }
            }
        }
            if haslevel {
                res = level
                level++
            }
    }

    return res
}

func dfs(grid [][]int, i, j, level int) {

    if i < 0 || i > len(grid)-1 || j < 0 || j > len(grid)-1 || grid[i][j] == level+1{
        return
    }
    if grid[i][j] == 0 {
        grid[i][j] = level+1
        return
    }
    grid[i][j] = level+1
    dfs(grid, i - 1, j, level)
    dfs(grid, i + 1, j, level)
    dfs(grid, i , j - 1, level)
    dfs(grid, i , j + 1, level)
}

```