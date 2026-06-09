
从 matrix 的最外层的各个点开始进行深度优先搜索 

用 1 代表可以流向太平洋，用 2 代表可以流向大西洋，在深度优先搜索的过程中进行 按位或 操作来更新流向 

最终如果某一个位置的值为 3 ,则表示可以同时流向两边

```swift

func pacificAtlantic(_ matrix: [[Int]]) -> [[Int]]  {

    let rows = matrix.count
    guard rows > 0 else { return [] }
    let cols = matrix[0].count
    
    let rowsRange = 0..<rows
    let colsRange = 0..<cols
    
    enum DFSState {
        case clear(row: Int, col: Int)
        case topMapped(row: Int, col: Int)
        case bottomMapped(row: Int, col: Int)
        case leftMapped(row: Int, col: Int)
        case rightMapped(row: Int, col: Int)
    }
    
    var flows = Array(repeating: Array(repeating: 0, count: cols), count: rows)
    var result = [[Int]]()
    
    let dfs: (Int, Int) -> Void = { (r, c) in
        var positions = [DFSState.clear(row: r, col: c)]
        while let last = positions.last {
            switch last {
                
            case let .clear(row: row, col: col):
                positions[positions.count - 1] = .topMapped(row: row, col: col)
                if rowsRange ~= row - 1,
                    matrix[row - 1][col] >= matrix[row][col],
                    flows[row - 1][col] | flows[row][col] > flows[row - 1][col] {
                    flows[row - 1][col] = flows[row - 1][col] | flows[row][col]
                    positions.append(.clear(row: row - 1, col: col))
                }
                
            case let .topMapped(row: row, col: col):
                positions[positions.count - 1] = .bottomMapped(row: row, col: col)
                if rowsRange ~= row + 1,
                    matrix[row + 1][col] >= matrix[row][col],
                    flows[row + 1][col] | flows[row][col] > flows[row + 1][col] {
                    flows[row + 1][col] = flows[row + 1][col] | flows[row][col]
                    positions.append(.clear(row: row + 1, col: col))
                }
                
            case let .bottomMapped(row: row, col: col):
                positions[positions.count - 1] = .leftMapped(row: row, col: col)
                if colsRange ~= col - 1,
                    matrix[row][col - 1] >= matrix[row][col],
                    flows[row][col - 1] | flows[row][col] > flows[row][col - 1] {
                    flows[row][col - 1] = flows[row][col - 1] | flows[row][col]
                    positions.append(.clear(row: row, col: col - 1))
                }
                
            case let .leftMapped(row: row, col: col):
                positions[positions.count - 1] = .rightMapped(row: row, col: col)
                if colsRange ~= col + 1,
                    matrix[row][col + 1] >= matrix[row][col],
                    flows[row][col + 1] | flows[row][col] > flows[row][col + 1] {
                    flows[row][col + 1] = flows[row][col + 1] | flows[row][col]
                    positions.append(.clear(row: row, col: col + 1))
                }
                
            case let .rightMapped(row: row, col: col):
                if flows[row][col] == 3 { result.append([row, col]) }
                positions.removeLast()
                
            }
        }
    }
    
    for row in 0..<rows {
        if flows[row][0] | 1 > flows[row][0] {
            flows[row][0] = flows[row][0] | 1
            dfs(row, 0)
        }
        
        if flows[row][cols - 1] | 2 > flows[row][cols - 1] {
            flows[row][cols - 1] = flows[row][cols - 1] | 2
            dfs(row, cols - 1)
        }
    }

    for col in 0..<cols {
        if flows[0][col] | 1 > flows[0][col] {
            flows[0][col] = flows[0][col] | 1
            dfs(0, col)
        }
        
        if flows[rows - 1][col] | 2 > flows[rows - 1][col] {
            flows[rows - 1][col] = flows[rows - 1][col] | 2
            dfs(rows - 1, col)
        }
    }
    
    return result
}


```