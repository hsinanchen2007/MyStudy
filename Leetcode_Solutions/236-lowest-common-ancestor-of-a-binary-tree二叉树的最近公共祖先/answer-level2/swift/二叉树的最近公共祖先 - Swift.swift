```
class Solution {
    func lowestCommonAncestor(_ root: TreeNode?, _ p: TreeNode?, _ q: TreeNode?) -> TreeNode? {
        if (root == nil || root === p || root === q) {return root}
        var left = lowestCommonAncestor(root!.left, p, q)
        var right = lowestCommonAncestor(root!.right, p, q)
        if left == nil {return right}
        if right == nil {return left}
        return root
    }
}
```