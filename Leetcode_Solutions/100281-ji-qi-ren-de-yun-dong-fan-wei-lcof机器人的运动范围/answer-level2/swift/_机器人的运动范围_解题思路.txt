### 解题思路
这道题和12题一样, 不过12题为了找到所有可能匹配的结果, 需要把每一个坐标都当作起点. 13题的起点固定在0,0; 相对简单一些.

本题还有一点需要注意的是, 如果一个格子符合条件后被计数了, 那么就标记为已访问, 下次回溯到这个节点, 无需重复进入了, 这是因为进入这个格子之后的情况已经计算过了

### 代码

```swift
class Solution {
    func movingCount(_ m: Int, _ n: Int, _ k: Int) -> Int {
        // 这道题的思路和12题一模一样, 只是能否进入下一个格子的条件变成 坐标位数之和是否小于k
        // 进入某个格子a后, a标记为true, 等回溯退回上一个格子后, 不需要把a标记为false.
        // 这是因为进入这个格子之后的情况已经计算过了, 无需重复计算.
        
        // 用于记录当前访问的路径, 避免循环访问
        if m == 0 || n == 0 {
            return 0
        }
        
        var visited = Array(repeating: false, count: m * n)
        
        return _checkIn(m, n, 0, 0, k, &visited)
    }
    
    /// 返回当前格子的, 后续格子, 能进入的总数
    func _checkIn(_ m: Int, _ n: Int, _ row: Int, _ col: Int, _ k: Int, _ visited: inout [Bool]) -> Int {
        
        
        var inNum = 0
        if !visited[row * n + col] && _sum(row, col) <= k {
            
            visited[row * n + col] = true
            inNum = 1
            
            // 左
            if col < n - 1 {
                inNum = inNum + _checkIn(m, n, row, col + 1, k, &visited)
            }
            // 右
            if col > 0 {
                inNum = inNum + _checkIn(m, n, row, col - 1, k, &visited)
            }
            // 下
            if row < m - 1 {
                inNum = inNum + _checkIn(m, n, row + 1, col, k, &visited)
            }
            // 上
            if row > 0 {
                inNum = inNum + _checkIn(m, n, row - 1, col, k, &visited)
            }
        }
        
        
        return inNum
    }
    
    
    /// 判断行列位数之和
    /// - Parameters:
    ///   - row: 行号
    ///   - col: 列号
    func _sum(_ row: Int, _ col: Int) -> Int {
        var sum = 0, row = row, col = col
        while row > 0 {
            sum = sum + row % 10
            row = row / 10
        }
        
        while col > 0 {
            sum = sum + col % 10
            col = col / 10
        }
        
        return sum
    }
}
```