```golang
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func isSameTree(p *TreeNode, q *TreeNode) bool {
    if (p == nil && q == nil) { // 节点都为空，也算结构相同
        return true
    } else if (p != nil && q != nil && p.Val == q.Val) { // 节点的值都一样，则递归比较左子树和右子树
        return isSameTree(p.Left, q.Left) && isSameTree(p.Right, q.Right)
    } else {
        return false
    }
}
```
