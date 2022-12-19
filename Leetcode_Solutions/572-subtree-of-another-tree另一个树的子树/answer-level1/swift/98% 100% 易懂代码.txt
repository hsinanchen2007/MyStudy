```
class Solution {
    func isSubtree(_ s: TreeNode?, _ t: TreeNode?) -> Bool {
        if s == nil {
            return false
        }
        if t == nil {
            return true
        }
        if isEqual(s, t) {
            return true
        }
        if isSubtree(s!.left, t) {
            return true
        }
        if isSubtree(s!.right, t) {
            return true
        }
        return false
    }
    func isEqual(_ s: TreeNode?, _ t: TreeNode?) -> Bool {
        if s == nil && t == nil {
            return true
        }
        if s == nil || t == nil {
            return false
        }
        if s!.val != t!.val {
            return false
        }
        if !isEqual(s!.left, t!.left) {
            return false
        }
        if !isEqual(s!.right, t!.right) {
            return false
        }
        return true
    }
}
```