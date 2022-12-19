### 解题思路
虽然这个问题使用递归法最简单。但是我想还需要使用非递归实现以下。

思路如下：
使用一个队列，一边不断入队左右节点，一边不断出队操作。并记录下每个节点的Depth，每当入队一次则Depth就在当前节点的Depth + 1。当遍历完树时，拿出最大Depth就可以。另外在循环前，队列要入队一个节点，这样才能把队列是否为空作为循环判断条件。

### 代码

```swift
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     public var val: Int
 *     public var left: TreeNode?
 *     public var right: TreeNode?
 *     public init(_ val: Int) {
 *         self.val = val
 *         self.left = nil
 *         self.right = nil
 *     }
 * }
 */
class Solution {
    func maxDepth(_ root: TreeNode?) -> Int {
        guard let _ = root else { return 0 }

        var depth = 0
        var n = (node: root, count: 1)
        var queue = [n]

        while !queue.isEmpty {
            let nodeCount = queue.removeFirst()
            if let _ = nodeCount.node {
                if depth < nodeCount.count { depth = nodeCount.count }

                n.count = nodeCount.count + 1

                n.node = nodeCount.node?.left
                queue.append(n)

                n.node = nodeCount.node?.right
                queue.append(n)
            }
        }
        return depth
    }
}
```