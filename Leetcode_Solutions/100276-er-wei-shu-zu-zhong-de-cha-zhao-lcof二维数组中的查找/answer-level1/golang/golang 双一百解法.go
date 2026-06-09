### 解题思路
由于该矩阵有序. 则每一行类似于区间 [n, m]

则判断每一行的区间是否包括 target. 如果包括,直接在该区间搜索即可.

### 代码

```golang
func findNumberIn2DArray(matrix [][]int, target int) bool {
    if    row := len(matrix) ; row == 0 {
        return false
    }

    column := len(matrix[0])
    if column == 0 {
        return false 
    }

    for _, a := range matrix {
        // if a[0] == target || a[column-1] == target{
        //     return true
        // }
        if a[0]<= target{
            if a[column-1] >= target{
                for _, k := range a {
                    if k == target {
                        return true
                    }
                }
            }
        }
    }
    return false
}
```