```
class Solution {
     func isSymmetric(_ root: TreeNode?) -> Bool {
        guard root != nil else {
            return true
        }
        return recur(root?.left, root?.right)
    }
    
    func recur(_ left: TreeNode?, _ right: TreeNode?) -> Bool {
        if left == nil && right == nil {
            return true
        }
        if left == nil || right == nil || left!.val != right!.val {
            return false
        }
        return recur(left!.left, right!.right) && recur(left!.right, right!.left)
    }
}
```