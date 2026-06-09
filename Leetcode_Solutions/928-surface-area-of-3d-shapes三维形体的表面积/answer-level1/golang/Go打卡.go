### 解题思路
此处撰写解题思路

### 代码

```golang
func surfaceArea(grid [][]int) int {
    if len(grid) == 0 {
        return 0
    }
    var (
        result = 0
        roof = 0
    )
    for i := 0; i < len(grid); i ++ {
        for j := 0; j < len(grid[0]); j ++ {
            if i == 0 {
                result += grid[i][j]
            }else if i-1 >= 0 && grid[i-1][j]-grid[i][j] > 0 {
                result += grid[i-1][j]-grid[i][j]
            }
            if j == 0 {
                result += grid[i][j]
            }else if j-1 >= 0 && grid[i][j-1]-grid[i][j] > 0 {
                result += grid[i][j-1]-grid[i][j]
            }
            if i == len(grid)-1 {
                result += grid[i][j]
            }else if i+1 < len(grid) && grid[i+1][j]-grid[i][j] > 0 {
                result += grid[i+1][j]-grid[i][j]
            }
            if j == len(grid[0])-1 {
                result += grid[i][j]
            }else if j+1 < len(grid[0]) && grid[i][j+1]-grid[i][j] > 0 {
                result += grid[i][j+1]-grid[i][j]
            }
            if grid[i][j] != 0 {
                roof ++
            }
        }
    }
    return result+2*roof
}
```