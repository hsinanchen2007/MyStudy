
递归法：

```swift []
class Solution {
    func hasPathSum(_ root: TreeNode?, _ sum: Int) -> Bool {
        guard let root = root else {
            return false
        }
        
        if root.val == sum, root.left == nil, root.right == nil {
            return true
        }
        
        let target = sum - root.val
        return hasPathSum(root.left, target) || hasPathSum(root.right, target)
    }
}
```
