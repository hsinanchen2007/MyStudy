### 解题思路
此处撰写解题思路

### 代码

```golang
func maxAreaOfIsland(grid [][]int) int {
    res := 0
    for i := 0; i < len(grid); i++ {
        for j := 0; j < len(grid[0]); j++ {
            temp := calcArea(i, j, grid)
            if temp > res {
                res = temp
            }
        }
    }
    return res
}

func calcArea(i, j int, grid [][]int) int {
    m := len(grid)
    n := len(grid[0])
    area := 0
    if grid[i][j] == 1 {
        //标记已查找过的点，避免重复计数
        grid[i][j] = 2
        area = 1
        if i - 1 >= 0 {
            area += calcArea(i - 1, j, grid)
        }
        if i + 1 < m {
            area += calcArea(i + 1, j, grid)
        }
        if j - 1 >= 0 {
            area += calcArea(i, j - 1, grid)
        }
        if j + 1 < n {
            area += calcArea(i, j + 1, grid)
        }
    }
    return area 
}
```