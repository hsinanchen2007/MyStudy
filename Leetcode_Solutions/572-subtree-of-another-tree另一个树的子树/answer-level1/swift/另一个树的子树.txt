
先序遍历数的每一个节点，去比对每个节点的子树是否和t相同



```swift []
class Solution {
    func isSubtree(_ s: TreeNode?, _ t: TreeNode?) -> Bool {
        
        guard let s = s, let t = t else {
            return true
        }
        var result = false
        preOrder(s) { (node) in
            result = result || compare(node, t)
            
        }
        
        return result
        
    }
    
    func preOrder(_ root: TreeNode?, _ excute: (TreeNode) -> Void) {
        guard let root = root else {
            return
        }
        
        excute(root)
        preOrder(root.left, excute)
        preOrder(root.right, excute)
    }
    
    func compare(_ s: TreeNode?, _ t: TreeNode?) -> Bool {
        if s == nil, t == nil {
            return true
        } else if (s != nil && t == nil) || (s == nil && t != nil) {
            return false
        }
        
        return s?.val == t?.val && compare(s?.left, t?.left) && compare(s?.right, t?.right)
    }
}
```
