
递归法

```swift []
class Solution {
    func isSymmetric(_ root: TreeNode?) -> Bool {
        guard let root = root else {
            return true
        }
        
        return compareIsSymmetric(root, root)
    }
    
    func compareIsSymmetric(_ p: TreeNode?, _ q: TreeNode?) -> Bool {
        guard let p = p, let q = q else {
            return true
        }
        
        var isSym = false
        
        if p.left?.val == q.right?.val, q.left?.val == p.right?.val {
            isSym = true
        }
        return isSym && compareIsSymmetric(p.left, q.right) && compareIsSymmetric(p.right, q.left)
    }
}
```

