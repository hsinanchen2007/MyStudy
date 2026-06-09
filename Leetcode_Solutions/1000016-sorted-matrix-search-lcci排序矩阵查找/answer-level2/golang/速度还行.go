```
func searchMatrix(matrix [][]int, target int) bool {
    //判断矩阵是否有效
    y := len(matrix)
    if y == 0 {
        return false
    }
    x := len(matrix[0])
    if x == 0 {
        return false
    }

    //查找
    for i := 0; i < y; i++ {
        //判断当行的范围
        if matrix[i][0] > target || matrix[i][x-1] < target {
            continue
        }
        //判断行中，防止查找最差情况
        if matrix[i][x/2] == target {
            return true
        }

        //查找
        if ok := twosearch(matrix[i], target); ok {
            return true
        }
    }
    return false
}

//两边向中间查找
func twosearch(m []int, target int) bool {
    length := len(m)
    i, j := 0, length - 1
    for i < j {
        if m[i] == target || m[j] == target {
            return true
        }
        i++
        j--
    }
    return m[i] == target
}
```
