

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
    func deepestLeavesSum(_ root: TreeNode?) -> Int {
        var maxDepth = 0
        var sum = 0
        func dfs(_ node: TreeNode?, depth: Int) {
            guard let node  = node  else {
                return
            }
            guard nil != node.left || nil != node.right else {
                if depth > maxDepth {
                    maxDepth = depth
                    sum = node.val
                } else if maxDepth == depth {
                    sum +=  node.val
                }
                return
            }
            dfs(node.left, depth: depth + 1)
            dfs(node.right, depth: depth + 1)
        }
        dfs(root, depth: 0)
        return sum
    }
 }
```