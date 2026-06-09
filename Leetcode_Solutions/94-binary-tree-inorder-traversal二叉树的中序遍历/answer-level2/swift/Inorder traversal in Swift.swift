递归实现：

```swift
class Solution {
    func inorderTraversal(_ root: TreeNode?) -> [Int] {
         guard let root = root else {
            return []
        }
        return inorderTraversal(root.left) + [root.val] + inorderTraversal(root.right)
    }
}
```