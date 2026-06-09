```
// 从右上角开始遍历
// 1. 向左遍历，找到第一个小于target的元素
// 2. 向下遍历，找到第一个大于target的元素
// 3. 循环1、2两步
// 初写有两个错处: 未判断矩阵列为0；见注释
func searchMatrix(matrix [][]int, target int) bool {
    if matrix == nil || len(matrix) == 0 || len(matrix[0])==0 {
        return false
    }
    m := len(matrix)
    n := len(matrix[0])
    idx := 0
    x,y := 0,n-1
    for {
        if idx%2 == 0 { // 1. 向左遍历，找到第一个小于target的元素
            for ;y>=0;y-- {
                if matrix[x][y] == target {
                    return true
                }
                if matrix[x][y] < target {
                    break
                }
            }
            if y == -1 { // 出错处，错误写法 y==0
                return false
            }
        } else { // 2. 向下遍历，找到第一个大于target的元素
            for ;x<m;x++ {
                if matrix[x][y] == target {
                    return true
                }
                if matrix[x][y] > target {
                    break
                }
            }
            if x == m { // 出错处，错误写法 x==m-1
                return false
            }
        }
        idx++
    }
    return false
}
```
