```
class Solution {
    func invertTree(_ root: TreeNode?) -> TreeNode? {
        if root == nil {
            return nil
        }
        
        let temp = root!.left
        root!.left = root!.right
        root!.right = temp
        
        invertTree(root?.left)
        invertTree(root?.right)
        
        return root
    }
}
```
经典翻转二叉树，据说做对了可以进Google;-)