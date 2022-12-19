### 解题思路
- BFS
### 代码

```swift
class Solution {
    func orangesRotting(_ grid: [[Int]]) -> Int {
        if grid.isEmpty {
            return -1
        }
        // 行
        let m = grid.count
        // 列
        let n = grid[0].count
        // 新鲜水果个数
        var fresh = 0
        var queue = [[Int]]()
        for i in 0..<m {
            for j in 0..<n {
                if grid[i][j] == 2 {
                    queue.append([i, j])
                } else if (grid[i][j] == 1) {
                    fresh += 1
                } 
            }
        }
        if fresh == 0 {
            return 0
        }
        var oranges = grid
        // 记录被橘子感染的四个方向
        let dirs = [[1 ,0], [-1, 0], [0, 1], [0, -1]]
        var minutes = 0
        while !queue.isEmpty && fresh > 0 {
            var size = queue.count 
            while size > 0 {
                let x = queue[0][0]
                let y = queue[0][1]
                queue.removeFirst()
                for i in 0..<4 {
                    let dx = x + dirs[i][0]
                    let dy = y + dirs[i][1]
                    // 越界、或者是新鲜的橘子
                    if dx < 0 || 
                    dx >= m ||
                    dy < 0 || 
                    dy >= n ||
                    oranges[dx][dy] != 1 {
                        continue
                    }
                    oranges[dx][dy] = 2
                    fresh -= 1
                    queue.append([dx, dy])
                }
                size -= 1
            }
            minutes += 1
        }
        return fresh > 0 ? -1:minutes
    }
}
```