m*n也可以旋转
第row行col列 转换后变为 所在的位置是 col行m-row-1
逆推下新的row行col列   m-1-col行row列
### 代码

```swift
class Solution {
    func rotate(_ matrix: inout [[Int]]) {
        var matrix0: [[Int]] = [[Int]]()
        let rows: Int = matrix.count
        let cols: Int = matrix[0].count
        for i in 0..<cols {
            var result: [Int] = [Int]()
            for j in 0..<rows {
                result.append(matrix[rows - j - 1][i])
            }
            matrix0.append(result)
        }
        matrix = matrix0
    }
}
```