暴力超时，dp[i][j] 表示(0,0)到[i,j]内元素之和，区域[r1,c1]->[r2,c2]内的元素和可以看成[0,0]到[r2,c2]的和减去[0,0]到[r1-1,c2]的和，再减去[0,0]到[r2,c1-1]的和，这两个区域有重叠，所以要加上多被减了一次的[0,0]到[r1-1,c1-1]的和

```swift
class NumMatrix {
    var dp: [[Int]] = [[]]
    init(_ matrix: [[Int]]) {
        let m = matrix.count
        if m > 0 {
            let n = matrix[m-1].count
            dp = Array(repeating: Array(repeating: 0, count: n + 1), count: m + 1)
            for i in 1...m {
                for j in 1...n {
                    dp[i][j] = dp[i][j-1] + dp[i-1][j] + matrix[i-1][j-1] - dp[i-1][j-1]
                }
            }
        }else{
            dp = []
        }
    }
    
    func sumRegion(_ row1: Int, _ col1: Int, _ row2: Int, _ col2: Int) -> Int {
        if dp.count == 0 {
            return 0
        }
        return dp[row2+1][col2+1] - dp[row1][col2+1] - dp[row2+1][col1] + dp[row1][col1]
    }
}

/**
 * Your NumMatrix object will be instantiated and called as such:
 * let obj = NumMatrix(matrix)
 * let ret_1: Int = obj.sumRegion(row1, col1, row2, col2)
 */
```