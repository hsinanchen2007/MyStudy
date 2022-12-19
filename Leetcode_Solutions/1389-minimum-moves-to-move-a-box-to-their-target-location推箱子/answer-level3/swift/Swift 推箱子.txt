### 解题思路

需要将Array中的元素按推箱子次数排序，每次从最小次数的元素搜索。

### 代码

```swift
class Solution {
    struct Position: Hashable {
        var px: Int = 0
        var py: Int = 0
        var bx: Int = 0
        var by: Int = 0
    }

    func minPushBox(_ grid: [[Character]]) -> Int {
        let m = grid.count
        let n = grid.first?.count ?? 0
        var position = Position()
        let xOffset = [0, -1, 0, 1]
        let yOffset = [-1, 0, 1, 0]
        var mayArray = [(Position, Int)]()
        var maySet = Set<Position>()
        for i in 0..<m {
            for j in 0..<n {
                if grid[i][j] == "B" {
                    position.bx = i
                    position.by = j
                }
                if grid[i][j] == "S" {
                    position.px = i
                    position.py = j
                }
            }
        }
        mayArray.append((position, 0))
        maySet.insert(position)
        while !mayArray.isEmpty {
            var tempArray = [(Position, Int)]()
            let last = mayArray.popLast()!
            let curCount = last.1
            for offset in 0...3 {
                var curP = last.0
                let offsetX = curP.px + xOffset[offset]
                let offsetY = curP.py + yOffset[offset]
                if offsetX >= m || offsetX < 0 || offsetY < 0 || offsetY >= n {
                    continue
                }
                if grid[offsetX][offsetY] == "#" {
                    continue
                }
                if offsetY != curP.by || offsetX != curP.bx {
                    curP.px = offsetX
                    curP.py = offsetY
                    if !maySet.contains(curP) {
                        maySet.insert(curP)
                        tempArray.append((curP, curCount))
                    }
                    continue
                }
                let boffsetX = curP.bx + xOffset[offset]
                let boffsetY = curP.by + yOffset[offset]
                if boffsetX >= m || boffsetX < 0 || boffsetY < 0 || boffsetY >= n {
                    continue
                }
                if grid[boffsetX][boffsetY] == "#" {
                    continue
                }
                if grid[boffsetX][boffsetY] == "T" {
                    return curCount + 1
                }
                curP.px = offsetX
                curP.py = offsetY
                curP.bx = boffsetX
                curP.by = boffsetY
                if !maySet.contains(curP) {
                    maySet.insert(curP)
                    tempArray.append((curP, curCount + 1))
                }
            }
            for cur in tempArray {
                var start = 0
                var end = mayArray.count - 1
                while start < end {
                    let mid = start + (end - start) / 2
                    let midCount = mayArray[mid].1
                    if cur.1 <= midCount {
                        start = mid + 1
                    } else if cur.1 > midCount {
                        end = mid - 1
                    }
                }
                mayArray.insert(cur, at: start)
            }
        }
        
        return -1
    }
}
```
