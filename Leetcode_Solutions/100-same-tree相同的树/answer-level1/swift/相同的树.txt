
递归法：
递归每一个树的节点，判断两棵树是否相同。


```swift []

class Solution {
    func checkNode(_ n1: TreeNode?, _ n2: TreeNode?, _ flag: inout Int) {
        
        guard let p = n1, let q = n2 else {
            if !(n1 == nil && n2 == nil){
                flag = flag + 1
            }
            return
        }
        
        if p.val != q.val {
            flag = flag + 1
        }
        checkNode(p.left, q.left, &flag)
        checkNode(p.right, q.right, &flag)
    }
    
    func isSameTree(_ p: TreeNode?, _ q: TreeNode?) -> Bool {
        var flag = 0
        checkNode(p, q, &flag)
        
        if flag > 0 {
            return false
        } else {
            return true
        }
    }
}

```

