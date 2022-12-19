### 解题思路
用for和if 组合成while循环  期待dalao有更骚的操作  go萌新一枚

先从第一行最后一列判断
+ 恰好等于target 直接返回
+ 大于target，则在这行中， col 列减少
+ 小于target，则在下面几行中

### 代码

```golang
func findNumberIn2DArray(matrix [][]int, target int) bool {
    if matrix == nil || len(matrix) == 0 {
        return false
    }
    row := 0;
    col := len(matrix[0]) - 1;
    for {
        if row >= len(matrix) || col < 0 {
            break;
        }
        if matrix[row][col] == target {
            return true
        } else if (matrix[row][col] > target) {
            col--
        } else {
            row++
        }
    }
    return false;

    
}
```