### 解题思路
此处撰写解题思路

### 代码

```golang
func maxAreaOfIsland(grid [][]int) int {
    if len(grid) == 0 {
        return 0
    }
    var (
        helper func(i,j int,temp *int)
        result = 0
    )
    helper = func(i,j int,temp *int) {
        grid[i][j] = -1
        *temp += 1
        if i-1 >= 0 && grid[i-1][j] == 1 {
            helper(i-1,j,temp)
        }
        if i+1 < len(grid) && grid[i+1][j] == 1 {
            helper(i+1,j,temp)
        }
        if j-1 >= 0 && grid[i][j-1] == 1 {
            helper(i,j-1,temp)
        }
        if j+1 < len(grid[0]) && grid[i][j+1] == 1 {
            helper(i,j+1,temp)
        }
    }
    for i := 0; i < len(grid); i ++ {
        for j := 0; j < len(grid[0]); j ++ {
            if grid[i][j] == 1 {
                temp := 0
                helper(i,j,&temp)
                if temp > result {
                    result = temp
                }
            }
        }
    }
    return result
}
```