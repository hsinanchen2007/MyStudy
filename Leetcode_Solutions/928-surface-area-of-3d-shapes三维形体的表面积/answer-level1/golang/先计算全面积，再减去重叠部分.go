### 解题思路
此处撰写解题思路

### 代码

```golang
func surfaceArea(grid [][]int) int {
    area := 0
    N := len(grid)
    for i := 0; i < N; i++ {
        for j := 0; j < N; j++ {
            if grid[i][j] > 0 {
                area = area + grid[i][j] * 4 + 2
                if i - 1 >= 0 {
                    if grid[i][j] > grid[i - 1][j] {
                        area -= grid[i - 1][j]
                    } else {
                        area -= grid[i][j]
                    }
                }
                if i + 1 < N {
                    if grid[i][j] > grid[i + 1][j] {
                        area -= grid[i + 1][j]
                    } else {
                        area -= grid[i][j]
                    }
                }
                if j - 1 >= 0  {
                    if grid[i][j] > grid[i][j - 1] {
                        area -= grid[i][j - 1]
                    } else {
                        area -= grid[i][j]
                    }
                }
                if j + 1 < N  {
                    if grid[i][j] > grid[i][j + 1] {
                        area -= grid[i][j + 1]
                    } else {
                        area -= grid[i][j]
                    }
                }
            }
        }
    }
    return area
}
```