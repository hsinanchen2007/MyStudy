```
//注意：
/*
 1.注意使用visited处理访问过的位置(这里使用一个小技巧，记录元素的序号)
 2.注意边界判断
 3.注意hasPath的循环终止条件，即if pathLength == word.count { return true } 位置。
 4.查找上左下右，使用两个数组，代码写起来更容易理解和不冗余。
 */
class Solution {
    let dx = [0,1,0,-1]
    let dy = [1,0,-1,0]
    func exist(_ board: [[Character]], _ word: String) -> Bool {
        guard board.count > 0 && word.count > 0 else {
            return false
        }
        var visited = [Int]()
        for i in 0..<board.count {
            for j in 0..<board.first!.count {
                if hasPath(board, i, j, word, 0, visited) {
                    return true
                }
                visited.removeAll()
            }
        }
        return false
    }
    
    func hasPath(_ board: [[Character]], _ row: Int, _ col: Int, _ word: String, _ pathLength: Int, _ visited: [Int]) -> Bool {
        let cur = board[row][col]
        let char = word[word.index(word.startIndex, offsetBy: pathLength)]
        var visited = visited
        var pathLength = pathLength
        if cur == char {
            visited.append(row * board.first!.count + col)
            pathLength += 1
            if pathLength == word.count {
                return true
            }
            for index in 0...3 {
                let newRow = row + dx[index]
                let newCol = col + dy[index]
                if newRow >= 0 && newRow < board.count && newCol >= 0 && newCol < board.first!.count {
                    if visited.contains(newRow * board.first!.count + newCol) {
                        continue
                    }
                    if hasPath(board, newRow, newCol, word, pathLength, visited) {
                        return true
                    }
                }
            }
        } else {
            return false
        }
        return false
    }
}

```