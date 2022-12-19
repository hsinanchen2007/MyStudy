### 解题思路
简单的方法，判断8个面的值，进行改值
### 代码

```swift
class Solution {
func gameOfLife(_ board: inout [[Int]]) {
        
        var returnBoard = board
        for i in 0 ..< board.count {
            
            let row:[Int] = board[i]
            
            for j in 0 ..< row.count {
                let val:Int = row[j]
                let newVal:Int = findAround(val, i, j, board)
                returnBoard[i][j] = newVal
            }
        }
        board = returnBoard
    }
    
    func findAround(_ val:Int, _ rowIndex:Int, _ columnIndex:Int, _ board:[[Int]]) -> Int {
        
        
        var liveCount = 0
        
        var frontRowIndex = -1
        var frontColumn = -1
        var endRowIndex = -1
        var endColumn = -1
        
        if rowIndex > 0 {
            frontRowIndex = rowIndex - 1
        }
        
        if columnIndex > 0 {
            frontColumn = columnIndex - 1
        }
        
        if rowIndex < board.count - 1 {
            endRowIndex = rowIndex + 1
        }
        
        if columnIndex < board[rowIndex].count - 1 {
            endColumn = columnIndex + 1
        }
        
        if frontRowIndex != -1 {
            
            let two = board[frontRowIndex][columnIndex]
            
            if two == 1 {
                liveCount = liveCount + 1
            }
            if frontColumn != -1 {
                let one = board[frontRowIndex][frontColumn]
                
                if one == 1 {
                    liveCount = liveCount + 1
                }
            }
            
            if endColumn != -1 {
                let three = board[frontRowIndex][endColumn]
                if three == 1 {
                    liveCount = liveCount + 1
                }
            }
        }
        
        if frontColumn != -1 {
            let four = board[rowIndex][frontColumn]
            if four == 1 {
                liveCount = liveCount + 1
            }
        }
        
        if endColumn != -1 {
            let five = board[rowIndex][endColumn]
            if five == 1 {
                liveCount = liveCount + 1
            }
        }
        
        if endRowIndex != -1 {
            
            let seven = board[endRowIndex][columnIndex]
            
            if seven == 1 {
                liveCount = liveCount + 1
            }
            if frontColumn != -1 {
                let six = board[endRowIndex][frontColumn]
                
                if six == 1 {
                    liveCount = liveCount + 1
                }
            }
            
            if endColumn != -1 {
                let eight = board[endRowIndex][endColumn]
                if eight == 1 {
                    liveCount = liveCount + 1
                }
            }
        }
        
        if val == 1 {
            
            if liveCount < 2 || liveCount > 3  {
                return 0
            } else {
                return 1
            }
            
        } else {
            if liveCount == 3  {
                return 1
            } else {
                return 0
            }
        }
        
    }
}
```