### 解题思路
此处撰写解题思路

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
func trimBST(root *TreeNode, L int, R int) *TreeNode {
	if root==nil{
		return nil
	}
	if root.Val>R{
		return trimBST(root.Left,L,R)
	}
	if root.Val<L{
		return trimBST(root.Right,L,R)
	}
	root.Left=trimBST(root.Left,L,R)
	root.Right=trimBST(root.Right,L,R)
	return root
}
```