（swift语法实现）
官方思路的第三种解法：
翻转代替旋转，先水平对称翻转，再主对角线翻转。

```
    func rotate(_ matrix: inout [[Int]]) {
        
        let row = matrix.count
        // 水平翻转
        for i in 0..<row {
            for j in 0..<Int(row/2) {
                (matrix[j][i], matrix[row - j - 1][i]) = (matrix[row - j - 1][i], matrix[j][i])
            }
        }
        // 主对角线翻转
        for i in 0..<row {
            for j in 0..<i {
                (matrix[i][j], matrix[j][i]) = (matrix[j][i], matrix[i][j])
            }
        }
    }
```
