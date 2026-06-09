```
func maxAreaOfIsland(grid [][]int) int {
    max := 0
    for i:=0;i<len(grid);i++{
        for j:=0;j<len(grid[0]);j++{
            if grid[i][j] == 1 {
                area := GetArea(grid, i, j)
                if area > max {
                    max = area
                }
            }
        }
    }
    return max
}

func GetArea(grid [][]int, i,j int) int {
    if i == len(grid) || i < 0 {
        return 0
    }
    if j == len(grid[0]) || j < 0 {
        return 0
    }
    if grid[i][j] == 1 {
        grid[i][j] = 0
        return 1 + GetArea(grid, i-1,j) + GetArea(grid, i+1,j) + GetArea(grid, i, j-1) + GetArea(grid, i, j+1)
    }
    return 0
}
```
