### 解题思路

DFS

### 代码

```swift
class Solution {
    func canVisitAllRooms(_ rooms: [[Int]]) -> Bool {
        var visited = [Int]()
        dfs(rooms, 0, &visited)
        return visited.count == rooms.count
    }
    func dfs(_ graph: [[Int]], _ cur: Int, _ visited: inout [Int]) {
        if visited.contains(cur) {
            return
        }
        visited.append(cur)
        for(_, next) in graph[cur].enumerated() {
            dfs(graph, next, &visited)
        }
    }
}
```