使用 BFS 思路。

```swift
class Solution {
    func levelOrder(_ root: TreeNode?) -> [[Int]] {
        guard let root = root else { return [] }
        
        var queue: [[TreeNode]] = [[root]]
        var result: [[Int]] = []
        
        while !queue.isEmpty {
            for _ in 0..<queue.count {
                let levelQueue = queue.removeFirst()
                var levelResult: [Int] = []
                var nexLevelQueue: [TreeNode] = []
                if levelQueue.isEmpty {
                    continue
                }
                for node in levelQueue {
                    levelResult.append(node.val)
                    if let left = node.left {
                        nexLevelQueue.append(left)
                    }
                    if let right = node.right {
                        nexLevelQueue.append(right)
                    }
                }
                if !nexLevelQueue.isEmpty {
                    queue.append(nexLevelQueue)
                }
                if !levelResult.isEmpty {
                    result.append(levelResult)
                }
            }
        }
        
        return result
    }
}
```