
### 代码

```swift
class Solution {
    func findMinHeightTrees(_ n: Int, _ edges: [[Int]]) -> [Int] {
        // 只有一个节点
        if n == 1 {
          return [0]
        }
        // 入度
        var degree = [Int](repeating: 0, count: n)
        // 建图
        var graph = [[Int]](repeating: [Int](), count: n)
        for (_, items) in edges.enumerated() {
            graph[items[0]].append(items[1])
            graph[items[1]].append(items[0])
            degree[items[0]] += 1
            degree[items[1]] += 1
        }
        // BFS遍历入度为1的点
        var queue: [Int] = []
        for i in 0..<n {
            if degree[i] == 1 {
                queue.append(i)
            }
        }
        var res = [Int]()
        while !queue.isEmpty {
            var tempList = [Int]()
            for _ in 0..<queue.count {
                let cur = queue.removeFirst()
                tempList.append(cur)
                for(_, nei) in graph[cur].enumerated() {
                    degree[nei] -= 1
                    if degree[nei] == 1 {
                        queue.append(nei)
                    }
                }
            }
            res = tempList
        }
        return res
    }
}
```