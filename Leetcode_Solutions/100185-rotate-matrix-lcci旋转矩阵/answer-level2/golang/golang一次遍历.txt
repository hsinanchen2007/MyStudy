思路就是大家都知道的转置之后每行反转，其实这两个操作完全可以再一次遍历中实现，没有必要做两次遍历。

```go
func rotate(matrix [][]int)  {
    if len(matrix) == 0 {
        return
    }
    m, n := len(matrix), len(matrix[0])

    for i := 0; i < m; i++ {
        for j := 0; j < n; j++ {
            if j > i {      // 当 j > i 时进行转置
                matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]
            }
            if j >= n / 2 {     // 遍历到每一行的后半部分时进行反转
                matrix[i][j], matrix[i][n-1-j] = matrix[i][n-1-j], matrix[i][j]
            }
        }
    }
}
```