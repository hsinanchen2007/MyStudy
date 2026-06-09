首先找到R的坐标，然后四个方向循环查找，找到B，直接退出，找到p，count+1，退出。
```
func numRookCaptures(_ board: [[Character]]) -> Int {
        var hor = 0
        var ver = 0
        var count = 0
        for (i,f) in board.enumerated(){
            for (index,value) in f.enumerated(){
                if value == "R"{
                    ver = i
                    hor = index
                }
            }
        }
        for i in 0..<hor {
            if board[ver][hor-i] == "B" {
                break
            }
            if board[ver][hor-i] == "p" {
                count += 1
                break
            }
        }
        for i in hor..<board[ver].count  {
            if board[ver][i] == "B" {
                break
            }
            if board[ver][i] == "p" {
                count += 1
                break
            }
        }
        for j in 0..<ver {
            if board[ver-j][hor] == "B" {
                break
            }
            if board[ver-j][hor] == "p" {
                count += 1
                break
            }
        }
        for j in ver..<board.count {
            if board[j][hor] == "B" {
                break
            }
            if board[j][hor] == "p" {
                count += 1
                break
            }
        }
        return count
    }
```
