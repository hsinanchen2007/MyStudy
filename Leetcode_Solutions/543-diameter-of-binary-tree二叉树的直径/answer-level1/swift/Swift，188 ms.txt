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
    func diameterOfBinaryTree(_ root: TreeNode?) -> Int {
        guard let root = root else { return 0 }
        let current = (maxDepth(root.left) + maxDepth(root.right))
        let sub = max(diameterOfBinaryTree(root.left), diameterOfBinaryTree(root.right))
        return max(current, sub)
    }
    
    func maxDepth(_ node: TreeNode?) -> Int {
        guard let node = node else { return 0 }
        return max(maxDepth(node.left), maxDepth(node.right)) + 1
    }
}
```