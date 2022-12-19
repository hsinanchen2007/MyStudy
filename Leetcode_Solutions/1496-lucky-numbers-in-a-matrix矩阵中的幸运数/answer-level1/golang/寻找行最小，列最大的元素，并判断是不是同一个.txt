### 解题思路
寻找行最小，列最大的元素，并判断是不是同一个

### 代码

```golang
func luckyNumbers (matrix [][]int) []int {
    rows, cols := len(matrix), len(matrix[0])
    res := make([]int, 0)
    for i := 0; i < rows; i++{
        //行最小
        left, right := 0, cols-1
        for left < right{
            if matrix[i][left] > matrix[i][right] {
                left++
            } else {
                right--
            }
        }
        //列最大
        up, down := 0, rows-1
        for up < down{
            if matrix[up][left] > matrix[down][left]{
                down--
            } else {
                up++
            }
        }
        //是不是同一行
        if i == up {
            res = append(res, matrix[up][left])
        }
    }
    return res
}
```