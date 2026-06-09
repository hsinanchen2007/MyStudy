如果某两个树p,q是对称的，则必须满足条件的条件是p.left==q.right,p.right==q.left!!!!!!!!!

```
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func isSymmetric(root *TreeNode) bool {
    if root==nil{
		return true
	}
	return isMirrorTree(root.Left,root.Right)
}
func isMirrorTree(p *TreeNode, q *TreeNode) bool {
	if p==nil&&q==nil{
		return true
	}
	if p==nil||q==nil{
		return false
	}
	if p.Val!=q.Val {
		return false
	}
	return isMirrorTree(p.Left,q.Right)&&isMirrorTree(p.Right,q.Left)
}
```
