### 解题思路
递归方式，每次放置一行的，放置后将与这一个皇后互斥的位置标记，当某一行无有效位置可以放置的时候，回朔到上一行

### 代码

```swift
class Solution {
    func totalNQueens(_ n: Int) -> Int {
        /// 修改二维数组的状态，放置一个皇后后，把与这个位置互斥的置0
        func placeOne(atRow row: Int, column: Int, queens: [[Int]]) -> [[Int]] {
            var tmpQueens = queens
            /// 行
            for i in 0..<queens.count {
                tmpQueens[row][i] = 0
            }
            /// 列
            for i in 0..<queens.count {
                tmpQueens[i][column] = 0
            }
            
            /// 斜对角线
            let rows = [1, -1, -1, 1]
            let columns = [1, -1, 1, -1]
            for index in 0...3 {
                var i = row
                var j = column
                while i < queens.count, i >= 0, j < queens.count, j >= 0 {
                    tmpQueens[i][j] = 0
                    i += rows[index]
                    j += columns[index]
                }
            }
            
            tmpQueens[row][column] = 1
            return tmpQueens
        }
        /// 递归搜索可以放置的位置
        func placeQueens(_ queens: [[Int]], row: Int, result: inout Int) -> [[Int]] {
            var tmpQueens = queens
            if row == queens.count {
                print(queens)
                result += 1
                return queens
            }
            for column in 0..<queens.count {
                tmpQueens = queens
                /// 当前行可以放置，才往下递归，否则直接回朔到上一行
                /// 判断当前位置是否可以放置
                if !(tmpQueens[row][column] == 0) {
                    tmpQueens = placeQueens(placeOne(atRow: row, column: column, queens: tmpQueens), row: row + 1, result: &result)
                }
            }
            
            return tmpQueens
        }
        
        /// 初始化一个二维数组，用-1初始化，-1表示可以放置，用0表示不可以放置，用1表示已经防止
        var queens = Array(repeating: Array(repeating: -1, count: n), count: n)
        var result = 0
        queens = placeQueens(queens, row: 0, result: &result)
        print(result)
        
        return result
    }
}
```