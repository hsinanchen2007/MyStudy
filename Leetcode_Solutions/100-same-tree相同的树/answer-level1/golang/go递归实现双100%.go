### 代码

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
    if p==nil||q==nil{
		return p==q
	}
	return isSameTree(p.Left,q.Left)&&isSameTree(p.Right,q.Right)&&p.Val==q.Val
}
```