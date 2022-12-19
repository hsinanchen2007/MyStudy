# 解法
创建二维矩阵，初始值填入一个元素 n * n，然后循环：
- 如果矩阵宽度等于 n，退出循环
- 右时针旋转矩阵
- 矩阵顶部逆序添加一行元素

![image.png](https://pic.leetcode-cn.com/8d43cd16f4de8dc0a69fbb5d6e6d13b00e0bf75c670b90f4d8b8050e161c9a3b-image.png)

# golang 代码
```go
func generateMatrix(n int) [][]int {
    if n <= 0 {
        return [][]int{}
    }
    ret := [][]int{{n * n}}
    cur := n * n - 1
    for {
        if len(ret) > 0 && len(ret[0]) == n {
            break
        }
        // 矩阵顺时针旋转 90 度
        ret = rightRotate(ret)
        // 矩阵顶部插入新行
        ret = append([][]int{{}}, ret[:]...)
        for i := 0; i < len(ret[1]); i++ {
            ret[0] = append([]int{cur}, ret[0]...)
            cur--
        }
    }
    return ret
}

func rightRotate(matrix [][]int) [][]int {
    if len(matrix) == 0 || len(matrix[0]) == 0 {
        return matrix
    }
    ret := make([][]int, len(matrix[0]))
    for i := len(matrix) - 1; i >= 0; i-- {
        for j := 0; j <len(matrix[0]); j++ {
            ret[j] = append(ret[j], matrix[i][j])
        }
    }
    return ret
}
```