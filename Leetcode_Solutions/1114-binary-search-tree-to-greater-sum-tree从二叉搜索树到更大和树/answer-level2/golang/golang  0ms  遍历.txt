从右子树开始遍历，一直累加sum值
- right -> root -> left
```
func bstToGst(root *TreeNode) *TreeNode {
	sum := 0
	btg(root, &sum)
	return root
}

func btg(root *TreeNode, sum *int) {
	if root == nil {
		return
	}
	btg(root.Right, sum)
	*sum += root.Val
	root.Val = *sum
	btg(root.Left, sum)
}
```