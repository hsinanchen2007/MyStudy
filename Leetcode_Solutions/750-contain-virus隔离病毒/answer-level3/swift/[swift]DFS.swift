### 解题思路

1. 每次遍历的时候需要记录感染区域的已经感染位置，将要感染位置，以及隔离需要的防火墙数。
2. 当感染区域全部被blocked或者所有位置都被感染，结束
3. 当只有一块感染区域，加上防火墙，结束
4. 当有多块感染区域，隔离即将感染位置最多的那一块，然后吧这个区域已经感染的位置加入blocked，把那些没有被隔离的感染区域的即将感染位置置位，表示明天开始的时候这些位置已经被感染了，接着进行下一轮。
5. 之所以采用复制grid，并修改其值的是因为过了一段时间之后，最初不同感染区域可能回相交，尝试过并查集，效果不理想。

### 代码

```swift
class Solution {
    private struct InfectedZone {
        var infected: Set<Int>
        var willBeInfected: Set<Int>
        var needWalls: Int
    }
    
    private let dx = [0,0,1,-1]
    private let dy = [1,-1,0,0]
    
    func containVirus(_ grid: [[Int]]) -> Int {
        
        
        let M = grid.count
        let N = grid[0].count
        
        var gridCopy = grid
        var totalWalls = 0
        
        var infected = Set<Int>()
        var blocked = Set<Int>()
        
        func valid(_ x: Int, _ y: Int) -> Bool {
            return x < M && x >= 0 && y >= 0 && y < N
        }
        
        var varius = [Int:InfectedZone]() //key: infected source value: varius
        func dfs(currentPosition: Int, source: Int) {
            for index in 0..<4 {
                let nextX = currentPosition >> 8 + dx[index]
                let nextY = currentPosition & 0xff + dy[index]
                if valid(nextX, nextY) {
                    let p = nextX << 8 | nextY
                    if gridCopy[nextX][nextY] == 0 {
                        varius[source]?.willBeInfected.insert(p)
                        varius[source]?.needWalls += 1
                    }
                    if gridCopy[nextX][nextY] == 1 && !infected.contains(p) && !blocked.contains(p){
                        infected.insert(p)
                        varius[source]?.infected.insert(p)
                        dfs(currentPosition: p, source: source)
                    }
                }
            }
        }
        
        while true {
            
            varius = [:]
            infected = []
            var infectedCount = 0

            for r in 0..<M {
                for c in 0..<N {
                    if gridCopy[r][c] == 1 {
                        infectedCount += 1
                        let source = r << 8 | c
                        if !infected.contains(source) && !blocked.contains(source) {
                            infected.insert(source)
                            varius[source] = InfectedZone(infected: [source], willBeInfected: [], needWalls: 0)
                            dfs(currentPosition: source, source: source)
                        }
                    }
                }
            }
            
            if varius.isEmpty || infectedCount == M * N{
                break
            }
            if varius.count == 1 {
                totalWalls += (varius.first?.value.needWalls ?? 0)
                break
            }
            let sortedVarius = varius.sorted { (varius1, varius2) -> Bool in
                varius1.value.willBeInfected.count > varius2.value.willBeInfected.count
            }
            totalWalls += sortedVarius[0].value.needWalls
            blocked = blocked.union(sortedVarius[0].value.infected)
            for index in 1..<sortedVarius.count {
                for nxt in sortedVarius[index].value.willBeInfected {
                    gridCopy[nxt >> 8][nxt & 0xff] = 1
                }
            }
        }

        return totalWalls
    }
 }
```