## 结果

![image.png](https://pic.leetcode-cn.com/19f899206dca391c5b23f44a8d256d6b1d6951bcf423296120403714d2c50575-image.png)

## 思路

不需要记录已经走过的路径，只需要不断重复右下左上并不断缩小边界即可

- 走完第一行，上边界下移
- 走完最后一列，右边界左移
- 走完最后一行，下边界上移
- 走完第一列，左边界右移
- 只需要走m*n次就可以走完整个矩阵

## Code

```
func spiralOrder(matrix [][]int) []int {
    m := len(matrix)
    if m == 0 {
        return []int{}
    }
    n := len(matrix[0])
    var result = make([]int, m*n)
    // 搜索方向0，1，2，3分别对应右下左上
    d := 0
    // 各个方向上的边界，到达边界都调转方向
    top, right, bottom, left := 0, n-1, m-1, 0
    var i, j int
    // 不断右下左上的走, 走m*n次
    for k:=0;k < m*n; {
        switch d {
            case 0:
            if j == right {
                // 走完第一行，上边界下移
                top++
                d = 1  
            }else {
                result[k] = matrix[i][j]
                k++
                j++
            }
            case 1:
            if i == bottom {
                // 走完最后一列，右边界左移
                right--
                d = 2
            }else {
                result[k] = matrix[i][j]
                k++
                i++
            }
            case 2:
            if j == left {
                // 走完最后一行，下边界上移
                bottom--
                d = 3
            }else {
                result[k] = matrix[i][j]
                k++
                j--
            }
            case 3:
            if i == top {
                // 走完第一列，左边界右移
                left++
                d = 0
            }else {
                result[k] = matrix[i][j]
                k++
                i--
            }
        }
    }
    return result
}
```

