### 解题思路
执行用时 :8 ms, 在所有 Go 提交中击败了90.43%的用户
内存消耗 :3.9 MB, 在所有 Go 提交中击败了92.42%的用户

动态规划从右上角到左上角遍历，计算每个位置到达右下角的最小路径
1. 先将最后一列和最后一行的遍历，因为它们只有一个方向可以走。
2. 从右下第二个遍历到左上第一个，输出结果

### 代码

```golang
func minPathSum(grid [][]int) int {

    if len(grid) == 0 {
        return 0
    }
    length := len(grid)
    size := len(grid[0])

    // length := len(grad)
    // dp := make([]int, length)
    // for i:=0; i<length; i++ {
    //     dp := make([]int, len(grad[i]))
    // }
    for i:=size-2; i>=0; i-- {
        grid[length-1][i] = grid[length-1][i] + grid[length-1][i+1]
    }
    for i:=length-2; i>=0; i-- {
        grid[i][size-1] = grid[i][size-1] + grid[i+1][size-1]
    }
    for i:=length-2; i>=0; i-- {
        for k:=size-2; k>=0; k-- {
            grid[i][k] = grid[i][k] + int(math.Min(float64(grid[i+1][k]), float64(grid[i][k+1])))
        }
    }
    return grid[0][0]
}
```