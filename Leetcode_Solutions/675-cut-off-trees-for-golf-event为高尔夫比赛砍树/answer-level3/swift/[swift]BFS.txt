### 解题思路
1. 便利获取需要砍得树，并按照高度排序
2. BFS计算从当前的位置到下一个位置的最短路径并求和

### 代码

```swift
class Solution {
    
    private let dx = [0,0,-1,1]
    private let dy = [1,-1,0,0]
    func cutOffTree(_ forest: [[Int]]) -> Int {
        guard !forest.isEmpty else {
            return 0
        }
        let M = forest.count
        let N = forest[0].count
        guard M *  N != 1 else {
            return 0
        }
        guard forest[0][0] != 0 else {
            return  -1
        }
        var trees = [Int:Int]()
        
        for r in 0..<M {
            for c in 0..<N {
                let p = r << 8 | c
                if forest[r][c] > 1 {
                    trees.updateValue(p, forKey: forest[r][c])
                }
            }
        }
        var startPosition = 0
        guard !trees.isEmpty else {
            return 0
        }
        var sortedTrees = trees.sorted { (arg0, arge1) -> Bool in
            arg0.key < arge1.key
        }
        if sortedTrees[0].value == startPosition {
            sortedTrees.removeFirst()
        }
        guard !sortedTrees.isEmpty else {
            return 0
        }
        
        func bfs(_ from: Int, to: Int) -> Int? {
            var queue = [Int]()
            queue.append(from)
            var visited = Array<Array<Bool>>(repeating: Array<Bool>(repeating: false, count: N), count: M)
            visited[from >> 8][from  & 0xff] = true
            var depth = 0
            while !queue.isEmpty {
                depth += 1
                var nextLevel = [Int]()
                for currentPosition in queue {
                    let r = currentPosition >> 8
                    let c = currentPosition & 0xff
                    for i in 0..<4 {
                        let nextX = r + dx[i]
                        let nextY = c + dy[i]
                        if nextX < M && nextX >= 0 && nextY >= 0 && nextY < N {
                            let nextPosition = nextX << 8 | nextY
                            guard nextPosition != to else {
                                return depth
                            }
                            if !visited[nextX][nextY]  && forest[nextX][nextY] != 0 {
                                nextLevel.append(nextPosition)
                                visited[nextX][nextY]  = true
                            }
                        }
                    }
                }
                queue = nextLevel
            }
            return nil
        }
        
        var ret = 0
        for (_,p) in sortedTrees  {
            guard let steps = bfs(startPosition, to: p) else {
                return -1
            }
            ret += steps
            startPosition = p
            
        }
        return ret
    }
 }
```