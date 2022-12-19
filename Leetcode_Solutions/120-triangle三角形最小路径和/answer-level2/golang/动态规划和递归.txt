### 解题思路
### 自底向上，对每个点进行遍历

### 代码

```golang
func minimumTotal(triangle [][]int) int {
    // return searchMin(triangle, 0, 0, len(triangle))
    length := len(triangle)
    f := make([][]int, length)
    for i := 0; i < length; i++ {
        f[i] = make([]int, i+1)
    }
    for i := 0; i< len(triangle); i++ {
        f[length-1][i] = triangle[length-1][i]
    }
    for i:= length-2; i>=0; i-- {
        for k:=0; k<i+1; k++ {
            f[i][k] = triangle[i][k] + int(math.Min(float64(f[i+1][k]), float64(f[i+1][k+1])))
        }
    }
    return f[0][0]
}

### 自顶向下

### 代码
func searchMin(triangle [][]int,  x, y, length int) int{
    
    if x == length {
        return 0
    }
    return int(math.Min(float64(triangle[x][y]+searchMin(triangle, x+1, y, len(triangle))), float64(triangle[x][y]+searchMin(triangle, x+1, y+1, len(triangle)))))
}
