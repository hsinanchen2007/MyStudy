### 解题思路
此处撰写解题思路

### 代码

```golang
func countServers(grid [][]int) int {
    if len(grid) == 0 {
        return 0
    }

    countH := make([]int, len(grid))
    countL := make([]int, len(grid[0]))

    for i1, v1 := range grid {
        for i2, v2 := range v1 {
            if v2 == 1 {
                countH[i1]++
                countL[i2]++
            }
        }
    }

    var res int
    for i1, v1 := range grid {
        for i2, v2 := range v1 {
            if v2 == 1 && (countH[i1] > 1 || countL[i2] > 1) {
                res++
            }
        }
    }

    return res
}
```