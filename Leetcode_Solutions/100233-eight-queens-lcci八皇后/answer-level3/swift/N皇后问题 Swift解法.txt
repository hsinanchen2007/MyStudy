N皇后问题
N皇后问题用到了回溯+剪枝的方式


### 代码

```swift
class Solution {
    private var cols: [Int] = [] // 存放是的某一行存储的皇后所在的列 cols[1] = 5（下标从0开始） 表示 第一行存储的皇后在在第5列
    private var nQueue: Int = 0
    private var ways: Int = 0
    
    private var results: [[String]] = [[String]]()
    
    func solveNQueens(_ n: Int) -> [[String]] {
        if n < 1 { return [] }
        nQueue = n
        cols = [Int](repeating: 0, count: nQueue)
        placeQueue(row: 0)
        print("\(ways)种解法")
        return results
    }
    
    func placeQueue(row: Int) {
        if row == nQueue {
            ways += 1
            var result: [String] = [String]()
            for row in 0..<nQueue {
                var rowStr = ""
                for col in 0..<nQueue {
                    if cols[row] == col {
                        rowStr.append("Q")
                    } else {
                        rowStr.append(".")
                    }
                }
                result.append(rowStr)
            }
            results.append(result)
            return
        }
        for col in 0..<nQueue {
            if isValidate(row: row, col: col) {
                cols[row] = col // 当前行存放的皇后的位置
                placeQueue(row: row + 1) // 回溯
            }
        }
    }
    
    func isValidate(row: Int, col: Int) -> Bool {
        for i in 0..<row {
            if cols[i] == col { return false } // 判断当前列是否存储有皇后
            if (row - i) == abs(Int(cols[i] - col)) { return false } // 对角线是否存储有皇后 对角线的斜率是1或者是-1因此用了系统的abs函数
        }
        return true
    }
}
```