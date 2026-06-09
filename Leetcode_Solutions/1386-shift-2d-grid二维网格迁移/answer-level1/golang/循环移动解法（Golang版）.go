**注意三点**
1、为避免重复移动，需对k用数组长度取余。
2、因为每次移动时最末尾成员会被挤掉，需要提前保存。
3、每行第0号成员被前一行末尾成员替代，需要做好判断。

**代码**
```
func shiftGrid(grid [][]int, k int) [][]int {
    m, n := len(grid), len(grid[0])
    k %= m * n

    for i := 0; i < k; i++ {
        t := grid[m-1][n-1]
        for j := m - 1; j >= 0; j-- {
            for l := n - 1; l > 0; l-- {
                grid[j][l] = grid[j][l-1]
            }
            if j > 0 {
                grid[j][0] = grid[j-1][n-1]
            }
        }
        grid[0][0] = t
    }

    return grid
}
```
