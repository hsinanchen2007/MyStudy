### 解题思路
由于题目说明行与列的数值都是逐渐递增的，故直接将数值与左下角的数进行比对；
如果目标数值比其小，则缩减矩阵一行；
如果比其大，则针对该行进行比对，如果在该行找不到对应数值，则继续缩减矩阵

### 代码

```golang
func findNumberIn2DArray(matrix [][]int, target int) bool {
    len_row := len(matrix)-1
    i, j := len_row, 0

    if len_row<0 {
        return false
    }

    len_col := len(matrix[0])-1

    for ;i>=0 && j<=len_col; {
        switch{
        case target < matrix[i][0]:
            i--
            j = 0
        case target >= matrix[i][0]:
            if target == matrix[i][j] {
                return true
            }
            j++
        }

        if j > len_col {
            i--
            j = 0
        }
    }

    return false
}
```