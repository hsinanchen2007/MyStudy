```
//这里掌握了bfs的模板，套用下基本可以解决，但是本题目定位为Easy，其他Medium的题目好像不是很服的样子。
bfs模板
```
visited = set()
def BFS(graph, start, end):
    if graph.root is None:
      return []

    queue = []
    queue.append([start])
    while queue:
        node = queue.pop()
        visited.add(node)

        process(node)
        nodeChildren = generateRelatedNodes(node)
        queue.push(nodeChildren)

    //other process work
    return processedNodes
```
class Solution3 {
    let dx = [0,1,0,-1]
    let dy = [1,0,-1,0]
    struct Pos {
        var row = 0
        var col = 0
        var minute = 0
    }
    func orangesRotting(_ grid: [[Int]]) -> Int {
        if grid.count == 0 {
            return 0
        }
        var grid = grid
        var queue = [Pos]()
        var minute = 0
        let maxRow = grid.count
        let maxCol = grid[0].count
        for row in 0..<maxRow {
            for col in 0..<maxCol {
                let num = grid[row][col]
                if num == 2 {
                    queue.append(Pos(row: row, col: col, minute: minute))
                }
            }
        }
        while !queue.isEmpty {
            let pos = queue.removeFirst()
            minute = pos.minute
            let row = pos.row
            let col = pos.col
            for i in 0...3 {
                let newRow = row + dx[i]
                let newCol = col + dy[i]
                if (newRow >= 0 && newRow < maxRow) &&
                    (newCol >= 0 && newCol < maxCol ) {
                    let newNum = grid[newRow][newCol]
                    if newNum == 1 {
                        grid[newRow][newCol] = 2
                        queue.append(Pos.init(row: newRow, col: newCol, minute: minute + 1))
                    }
                }
            }
        }
        print(grid)
        if countOfOne(grid) {
            return -1
        }
        return minute
    }
    
    func countOfOne(_ grid:[[Int]]) -> Bool {
        var countOfOne = 0

        for row in grid {
            for num in row {
                if num == 1 {
                    countOfOne += 1
                }
            }
        }
        return countOfOne > 0
    }
}
```