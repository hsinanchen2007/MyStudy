### 解题思路
DFS
### 代码

```swift
class Solution {
    func eventualSafeNodes(_ graph: [[Int]]) -> [Int] {
        // 0: 默认
        // 1: visiting
        // 2: safe
        // 3: unsafe
        let num = graph.count
        var states = [Int](repeating: 0, count: graph.count)
        var res = [Int]()
        for i in 0..<num {
            if self.dfs(graph, i, states: &states) == 2 {
                res.append(i)
            }
        }
        return res
    }
    func dfs(_ graph: [[Int]], _ cur: Int, states: inout [Int]) -> Int {
        if states[cur] == 1 {
            // 表示访问中, 如果再次访问到表示有环. 则不安全
            return 3
        }
        if states[cur] != 0 {
            return states[cur]
        }
        states[cur] = 1
        for(_, next) in graph[cur].enumerated() {
            if dfs(graph, next, states: &states) == 3 {
                states[cur] = 3
                return states[cur]
            }
        }
        states[cur] = 2
        return states[cur]
    }
}
```