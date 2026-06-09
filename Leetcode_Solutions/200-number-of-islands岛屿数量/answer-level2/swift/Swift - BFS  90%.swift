```
class Solution {
    let dx = [0, 1, 0, -1] //寻找邻居x轴上、左、下、右
    let dy = [1, 0, -1, 0] //寻找邻居y轴上、左、下、右
    func numIslands(_ grid: [[Character]]) -> Int {
        if grid.count == 0 {
            return 0
        }
        var grid = grid
        var res = 0
        var queue = [Node]()
        for row in 0..<grid.count {
            for col in 0..<grid[0].count {
                let cur = grid[row][col]
                if cur == "1" {
                    grid[row][col] = "2" //访问过的设置为2
                    queue.append(Node.init(row, col))
                    while !queue.isEmpty {
                        let node = queue.removeFirst()
                        for i in 0...3 { //遍历周边的几个，如果也是1放入到queue中，queue没有元素后，说明这个孤岛遍历完毕。
                            let drow = node.row + dx[i]
                            let dcol = node.col + dy[i]
                            if (drow >= 0 && drow < grid.count) && (dcol >= 0 && dcol < grid[0].count) {
                                let dchar = grid[drow][dcol]
                                if dchar == "1" && dchar != "2" {
                                    grid[drow][dcol] = "2"
                                    queue.append(Node.init(drow, dcol))
                                }
                            }
                        }
                    }
                    res += 1
                }
            }
        }
        return res
    }
}
```