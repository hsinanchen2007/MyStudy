## 结果

![image.png](https://pic.leetcode-cn.com/9942e35effde1e1da1f5e7911024fd69fcbdc47c9271bfcc3ed73cb2abacd940-image.png)

## 思路

类似螺旋矩阵的题目

- 首先构建n*n的矩阵，设需要填入的数K从1到n*n
- 设定矩阵的四个边界t,r,b,l分别代表top、right、bottom、left，初始为0,n-1,n-1,0
- 设定变量d代表行走方向，0，1，2，3分别代表向右、下、左、上
- 开始按照题目约定顺时针方向走，走到边界的同时转向并缩小走过的边界

## Code

```
func generateMatrix(n int) [][]int {
    result := make([][]int, n)
    if n == 0 {
        return result
    }
    for i := range result {
        result[i] = make([]int, n)
    }
    d := 0
    // 边界
    t, r, b, l := 0, n-1, n-1, 0
    var i, j = 0, 0
    for k:=1; k<=n*n;  {
        switch d {
            case 0:
            if j == r {
                // 走到右边界，缩小上边界
                d = 1
                t++
            } else {
                result[i][j] = k
                k++
                j++
            }
            case 1:
            if i == b {
                // 走到下边界，缩小右边界
                d = 2
                r--
            } else {
                result[i][j] = k
                k++
                i++
            }
            case 2:
            if j == l {
                // 走到左边界，缩小下边界
                d = 3
                b--
            } else {
                result[i][j] = k
                k++
                j--
            }
            case 3:
            if i == t {
                // 走到上边界，缩小左边界
                d = 0
                l++
            } else {
                result[i][j] = k
                k++
                i--
            }
        }
    }
    return result
}
```

