```golang
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func isSymmetric(root *TreeNode) bool {
    if root == nil {
        return true
    }
    
    return isSameTree(root.Left, root.Right)
}

func isSameTree(l *TreeNode, r *TreeNode) bool {
    if (l == nil && r == nil) {
        return true
    } else if (l != nil && r != nil && l.Val == r.Val) { // 这里按照对称位置比对子树即可
        return isSameTree(l.Left, r.Right) && isSameTree(l.Right, r.Left)
    } else {
        return false
    }
}
```
