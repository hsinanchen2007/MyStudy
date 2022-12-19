

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
    return isMillor(root,root)
}

func isMillor(p,q *TreeNode)bool{
    if p == nil && q== nil{
        return true
    }
    if p == nil || q == nil{
        return false
    }
    return p.Val==q.Val&&isMillor(p.Left,q.Right)&&isMillor(p.Right,q.Left)
}
```