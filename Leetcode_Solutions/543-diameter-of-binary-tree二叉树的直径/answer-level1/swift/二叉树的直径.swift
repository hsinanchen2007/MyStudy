
深度优先搜索，找出树的每个节点左右节点之和，记录最大值

```swift []
class Solution {

    func diameterOfBinaryTree(_ root: TreeNode?) -> Int {
        guard let root = root else {
            return 0
        }
        
        var len = 0
        preOrder(root) { (node) in
            let leftDep = depth(node.left)
            let rightDep = depth(node.right)
            len = max(len, leftDep + rightDep)
        }

        return len
    }
    
    func depth(_ root: TreeNode?) -> Int {
        guard let root = root else {
            return 0
        }
        let leftDep = depth(root.left)
        let rigthDep = depth(root.right)
        return max(leftDep, rigthDep) + 1
    }
    
    func preOrder(_ root: TreeNode?, _ excute: (TreeNode) -> Void) {
        guard let root = root else {
            return
        }
        
        excute(root)
        preOrder(root.left, excute)
        preOrder(root.right, excute)
    }
}
```

