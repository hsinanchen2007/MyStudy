### 解题思路

- 暴力解法
- 首先找出`R`的位置
- 对`R`分别上下左右移动，遇到友方`B`停止，遇到`p`结果+1并停止，到达边缘也停止

### 代码

```swift
class Solution {
    func numRookCaptures(_ board: [[Character]]) -> Int {
         if board.count == 0 {
            return 0
        }
        let row = board.count
        let col = board[0].count
        var r = 0
        var c = 0
        
        for i in 0..<row {
            for j in 0..<col {
                if board[i][j] == "R" {
                    r = i
                    c = j
                }
            }
        }
        var res = 0
        var top = r - 1
        var bottom = r + 1
        var left = c - 1
        var right = c + 1
        while top >= 0 {
            let v = board[top][c]
            if v == "B" {
                break
            }
            if v == "p" {
                res += 1
                break
            }
            top -= 1
        }
        while bottom < row {
            let v = board[bottom][c]
            if v == "B" {
                break
            }
            if v == "p" {
                res += 1
                break
            }
            bottom += 1
        }
        while left >= 0 {
            let v = board[r][left]
            if v == "B" {
                break
            }
            if v == "p" {
                res += 1
                break
            }
            left -= 1
        }
        while right < col {
            let v = board[r][right]
            if v == "B" {
                break
            }
            if v == "p" {
                res += 1
                break
            }
            right += 1
        }
        return res
    }
}
```