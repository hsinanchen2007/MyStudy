遍历每个格子，当格子不在矩阵边缘时，减去可能的重叠计算的面积。

注意当grid[i][j]为零时，不需要计算，直接下一个。

```go
func surfaceArea(grid [][]int) int {
    ans := 0
    for i := range grid {
        for j := range grid[i] {
            if grid[i][j] == 0 {
                continue
            }

            ans += grid[i][j] * 4 + 2
            
            if i > 0 {
                ans -= 2 * min(grid[i-1][j], grid[i][j])
            }

            if j > 0 {
                ans -= 2 * min(grid[i][j-1], grid[i][j])
            }
        }
    }

    return ans
}

func min(x, y int) int {
    if x < y {
        return x
    }
    return y
}
```
