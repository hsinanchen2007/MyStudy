### 解题思路
取出横向和纵向数据，进行遍历

### 代码

```swift
class Solution {

    func numRookCaptures(_ board: [[Character]]) -> Int {
        
        var row = 0
        var colnum = 0
        
        var count = 0
        
        for i in 0 ..< board.count {
            
            let arr:[Character] = board[i]
            
            for j in 0 ..< arr.count {
                
                let chara:Character = arr[j]
                
                if chara == "R" {
                    
                    row = i
                    colnum = j
                    break;
                }
            }
        }
        
        let rowBoards = board[row]
        
        let char1: Character = "-"

        var colnumBoards = Array.init(repeating: char1, count: board.count)
        
        for i in 0 ..< board.count {
            
             let arr:[Character] = board[i]
            let colnumVal = arr[colnum]
            colnumBoards[i] = colnumVal
        }
        
        
        
        // colnum
        for i in (0 ..< row).reversed()  {
            let colnumVal = colnumBoards[i]
            
            if colnumVal == "B" {
                break;
            }
            if colnumVal == "p" {
                count = count + 1
                break;
            }
            
            
        }
        
        for i in row ..< colnumBoards.count {
            
             let colnumVal = colnumBoards[i]
            if colnumVal == "B" {
                break;
            }
            if colnumVal == "p" {
                count = count + 1
                break;
            }
        }
        
        
        
        for i in (0 ..< colnum).reversed()  {
            let colnumVal = rowBoards[i]
            
            if colnumVal == "B" {
                break;
            }
            if colnumVal == "p" {
                count = count + 1
                break;
            }
            
            
        }
        
        for i in colnum ..< rowBoards.count {
            
             let colnumVal = rowBoards[i]
            if colnumVal == "B" {
                break;
            }
            if colnumVal == "p" {
                count = count + 1
                break;
            }
        }
        
        
        return count
        
        
        
    }
}
```