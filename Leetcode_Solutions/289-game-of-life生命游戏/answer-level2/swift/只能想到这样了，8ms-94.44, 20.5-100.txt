遍历一遍，把当前位置的细胞的下一个状态储存下来。
然后给已经不受影响的细胞更改状态

```
    func gameOfLife(_ board: inout [[Int]]) {
        var m = 0
        var changedArray = Array<Int>()
        while m - 2 < board.count {
            var n = 0
            while n  - 2 < board.first!.count {
                if m < board.count && n < board.first!.count {
                    // 当前细胞的下一个状态
                    let nextStatus = liveReload(board: board, row: m, line: n)
                    changedArray.append(nextStatus)
                }
                if m >= 2 && n >= 2 {
                    board[m-2][n-2] = changedArray.first!
                    changedArray.remove(at: 0)
                }
                n = n + 1
            }
            m = m + 1
        }
    }
    
    
    func liveReload(board : [[Int]], row:Int, line:Int ) -> Int {
        var m = -1
        var liveCount = 0
        while m  < 2 {
            var n = -1
            while n < 2 {
                if line + n >= 0 && line + n < board.first!.count &&
                    row + m >= 0 && row + m < board.count && !(m == 0 && n == 0) {
                    let status = board[m + row][n + line]
                    if status > 0 {
                        liveCount = liveCount + 1
                    }
                }
                n = n + 1
            }
            m = m + 1
        }
        
        let curStatus =  board[row][line]
        if curStatus > 0 {
            if liveCount < 2 {
                return 0
            }else if liveCount < 4 {
                return 1
            }else {
                return 0
            }
        }else {
            if liveCount == 3 {
                return 1
            }
            return 0
        }
    }

```
