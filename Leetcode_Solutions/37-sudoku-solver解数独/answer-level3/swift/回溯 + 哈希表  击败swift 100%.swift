```
class Solution {
    var rows = Array.init(repeating: [Character: Int](), count: 9)
    var columns = Array.init(repeating: [Character: Int](), count: 9)
    var boxes = Array.init(repeating: [Character: Int](), count: 9)
    var spaces = [(Int, Int)]()
    func solveSudoku(_ board: inout [[Character]]) {
        for i in 0..<9 {
            for j in 0..<9 {
                let c = board[i][j]
                if c == "." {
                    spaces.append((i, j))
                } else {
                    rows[i][c] = 1
                    columns[j][c] = 1
                    boxes[i / 3 * 3 + j / 3][c] = 1
                }
            }
        }
        var index = 0
        while index < spaces.count {
            if place(board: &board, index: index) {
                index += 1
            } else {
                guard index > 0 else {
                    return
                }
                index -= 1
            }
        }
    }
    
    func place(board: inout [[Character]], index: Int) -> Bool {
        let location = spaces[index]
        let i = location.0
        let j = location.1
        let box = i / 3 * 3 + j / 3
        let c_temp = board[i][j]
        for c in 1...9 {
            let char = Character.init("\(c)")
            if c_temp.asciiValue! >= char.asciiValue! {
                continue
            }
            if rows[i][char] != nil || columns[j][char] != nil || boxes[box][char] != nil {
                continue
            }
            rows[i][char] = 1
            columns[j][char] = 1
            boxes[box][char] = 1
            board[i][j] = char
            break
        }
        if c_temp != "." {
            rows[i].removeValue(forKey: c_temp)
            columns[j].removeValue(forKey: c_temp)
            boxes[box].removeValue(forKey: c_temp)
        }
        if board[i][j] != c_temp {
            return true
        } else {
            board[i][j] = "."
            return false
        }
    }
}
```