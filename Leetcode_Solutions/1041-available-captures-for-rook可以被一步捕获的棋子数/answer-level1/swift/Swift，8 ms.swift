思路：

1. 查找炮 `R` 和兵 `p` 位置并缓存；
2. 遍历兵数组，若与炮不在同一行且不在同一列则跳过；
3. 若在同一行或同一列，则判断炮与兵之间是否全为空格 `.`，若不是，则跳过，若是，则计数加一；
4. 遍历完成，返回计数。
<br>
```swift
class Solution {
    typealias Position = (x: Int, y: Int)
    
    func numRookCaptures(_ board: [[Character]]) -> Int {
        let size = board.count
        var pao = Position(x: 0, y: 0)
        var bins = [Position]()
        for x in 0..<size {
            for y in 0..<size {
                let item = board[x][y]
                switch item {
                case Character("R"):
                    pao.x = x
                    pao.y = y
                case Character("p"):
                    bins.append(Position(x: x, y: y))
                default:
                    continue
                }
            }
        }
        var ans = 0
        for bin in bins {
            var able = true
            if bin.x == pao.x {
                let range = (bin.y > pao.y ? (pao.y + 1)..<bin.y : (bin.y + 1)..<pao.y)
                for y in range {
                    if board[bin.x][y] != Character(".") {
                        able = false
                        break
                    }
                }
            } else if bin.y == pao.y {
                let range = (bin.x > pao.x ? (pao.x + 1)..<bin.x : (bin.x + 1)..<pao.x)
                for x in range {
                    if board[x][bin.y] != Character(".") {
                        able = false
                        break
                    }
                }
            } else {
                able = false
            }
            if able {
                ans += 1
            }
        }
        return ans
    }
}
```