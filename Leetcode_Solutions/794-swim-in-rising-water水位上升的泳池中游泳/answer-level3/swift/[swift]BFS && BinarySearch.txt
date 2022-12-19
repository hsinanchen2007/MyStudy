### 解题思路

1. 二分法枚举可能的时间
2. BFS判断是否可以到达最后的位置

### 代码

```swift
 class Solution {
    private let dx = [0,0,1,-1]
    private let dy = [1,-1,0,0]
    
    func swimInWater(_ grid: [[Int]]) -> Int {
        
        let N = grid.count
        var canReachMinHeight = -1
        
        func canReach(_ position: Int,_ waterHeight: Int) -> Bool {
            
            var queue = [Int]()
            queue.append(0)
            
            var visited = Array<Array<Bool>>(repeating: Array<Bool>(repeating: false, count: N), count: N)
            visited[0][0] = true
            
            while !queue.isEmpty {
                var nextLevel = [Int]()
                for p in queue {
                    let x = p & 0xff
                    let y = p >> 8
                    for index in 0..<4 {
                        let  nextX = x + dx[index]
                        let  nextY = y + dy[index]
                        if nextX >= 0 &&  nextX < N && nextY >= 0 && nextY < N && !visited[nextX][nextY] && grid[nextX][nextY] <= waterHeight {
                            guard nextY != N  - 1 || nextX !=  N - 1 else {
                                canReachMinHeight = waterHeight
                                return true
                            }
                            visited[nextX][nextY]  = true
                            nextLevel.append(nextY << 8 | nextX)
                        }
                    }
                }
                queue = nextLevel
            }
            
            return false
        }
        
        var left = grid[0][0]
        let maxHeight = grid.map {$0.max()!}.max()!
        guard left < maxHeight else {
            return left
        }
        var right = maxHeight + 1
        while left < right {
            let mid =  left + (right -  left) >> 1
            if canReach(0,mid) {
                right = mid
            }  else {
                left = mid + 1
            }
        }
        
        guard left < canReachMinHeight else {
            return canReachMinHeight
        }
        return canReach(0,left) ? left : canReachMinHeight
    }
 }
```