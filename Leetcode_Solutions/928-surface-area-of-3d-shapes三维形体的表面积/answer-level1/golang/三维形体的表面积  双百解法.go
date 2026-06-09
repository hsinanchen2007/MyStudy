思想很简单依次遍历，主要优化是：由于由左上往右下遍历，因此可以省去对左和上的判断。
![image.png](https://pic.leetcode-cn.com/68d251eb85d1ba196428680f92f8cd4d9da0221ef3358e5f12d5fd7e83250073-image.png)
```
func GetMin(val1 int, val2 int) int {
    if val1 < val2 {
        return val1
    }
    return val2
}
func surfaceArea(grid [][]int) int {
    rows := len(grid)
    cols := len(grid[0])
    cnt := 0
 
    for i := 0; i < rows; i++ {
        for j := 0; j < cols; j++ {
            if grid[i][j] != 0 {

            begin := 6 + 4 * (grid[i][j] - 1)
            // 下方向
            if i + 1 < rows && grid[i + 1][j] != 0 {
                begin -= GetMin(grid[i][j], grid[i + 1][j]) * 2
            }
            // 右方向
            if j + 1 < cols && grid[i][j + 1] != 0 {
                begin -= GetMin(grid[i][j], grid[i][j + 1]) * 2
            }
            
            cnt += begin
            }
        }
    }

    return cnt
}
```
