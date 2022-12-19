### 动态规划
看代码注释
### 代码

```swift
class NumMatrix {
    private var sums: [[Int]] = [[]]

    init(_ matrix: [[Int]]) {
        if matrix.isEmpty {
            return
        }
     // sums[i][j] = sum(matrix[0][0] ~ matrix[i - 1][j - 1])
        sums = [[Int]](repeating: [Int](repeating: 0, count: matrix[0].count + 1), count: matrix.count + 1)
        for i in 1...matrix.count {
            for j in 1...matrix[0].count {
                // 由于上面sums默认扩充了一行一列所以在计算当前位置大小的时候需要 - 1
                // sums的和只和当前位置 / 左边 / 左上角 / 上面有关系
                // 在计算和的时候 [i-1, j - 1]到[0, 0]的和被重复计算了所以需要 - sums[i - 1][j - 1]
                sums[i][j] = matrix[i - 1][j - 1] 
                + sums[i - 1][j]
                + sums[i][j - 1] 
                - sums[i - 1][j - 1]
            }
        }
        
    }
    
    func sumRegion(_ row1: Int, _ col1: Int, _ row2: Int, _ col2: Int) -> Int {

        // 由于sums多了一行一列所以计算[row2, col2]的时候需要 + 1
        // sums和等于 row2, col2] -> [0, 0]的和 - 上面的和 - 左边的和 +（上面和左边重复减去的和）
        return sums[row2 + 1][col2 + 1] 
        - sums[row2 + 1][col1]
        - sums[row1][col2 + 1] 
        + sums[row1][col1]
    }
}

/**
 * Your NumMatrix object will be instantiated and called as such:
 * let obj = NumMatrix(matrix)
 * let ret_1: Int = obj.sumRegion(row1, col1, row2, col2)
 */
```