### 解题思路
递归解法

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
    var nodeArray:[Int] = []
    func inorderTraversal(_ root: TreeNode?) -> [Int] {
        guard root != nil else{
            return []
        }
        self._traver(root!)
        return nodeArray
    }

    func _traver( _ node : TreeNode) {
        if let nleft = node.left {
            _traver(nleft)
        }
        self.nodeArray.append(node.val)

        if let nright = node.right {
            _traver(nright)
        }
    }
}
```