```javascript []
class Solution {
    func isSymmetric(_ root: TreeNode?) -> Bool {
        return isMirror(root, root)
    }
    
    func isMirror(_ left: TreeNode?, _ right: TreeNode?) -> Bool {
        if left == nil && right == nil {
            return true
        }
        if left == nil || right == nil {
            return false
        }
        return (left!.val == right!.val) && isMirror(left!.left, right!.right) && isMirror(left!.right, right!.left)
    }
}
```

