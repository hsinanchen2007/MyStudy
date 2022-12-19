```
class Solution {
    func lcaDeepestLeaves(_ root: TreeNode?) -> TreeNode? {
        if root == nil {
            return nil
        }
        let left = treeHeight(root?.left)
        let right = treeHeight(root?.right)
        if left == right {
            return root
        }else if left > right {
            return lcaDeepestLeaves(root?.left)
        }else{
            return lcaDeepestLeaves(root?.right)
        }
    }
    
    func treeHeight(_ root: TreeNode?) -> Int {
        if root == nil {
            return 0
        }
        let left = treeHeight(root?.left)
        let right = treeHeight(root?.right)
        return 1 + max(left, right)
    }
}
```