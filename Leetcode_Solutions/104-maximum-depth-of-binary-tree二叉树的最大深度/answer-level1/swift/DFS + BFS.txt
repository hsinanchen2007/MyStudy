### 解题思路
此处撰写解题思路

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
//BFS
func maxDepth(_ root: TreeNode?) -> Int {
    guard let tmpRoot = root else { return 0 }
    var queue = [tmpRoot]
    var depth = 0
    while !queue.isEmpty {
        depth += 1
        queue = queue.flatMap { [$0.left, $0.right].compactMap { $0 } }
    }
    return depth
}

//DFS
func maxDepth(_ root: TreeNode?) -> Int {
    guard root != nil else { return 0 }
    return max(maxDepth(root?.left), maxDepth(root?.right)) + 1
}
}
```