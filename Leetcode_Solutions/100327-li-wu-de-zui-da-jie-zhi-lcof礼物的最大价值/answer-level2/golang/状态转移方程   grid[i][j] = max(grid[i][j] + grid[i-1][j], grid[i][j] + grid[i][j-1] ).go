### 解题思路
此处撰写解题思路

### 代码

```golang
func maxValue(grid [][]int) int {
    row := len(grid)
    column := len(grid[0])
    for i := 0; i < row; i++ {
        for j :=0; j < column; j++ {
            grid[i][j] = Max(grid, i,j)
        }
    }
    return grid[row-1][column-1]
}

func Max(grid [][]int,i,j int) int{
    max := grid[i][j]

    if i-1 >=0 {
        if grid[i][j] + grid[i-1][j] > max {
            max = grid[i][j] + grid[i-1][j]
        }
    }
     if j-1 >=0 {
        if grid[i][j] + grid[i][j-1] > max {
            max = grid[i][j] + grid[i][j-1]
        }
    }
    return max
}
```