```
func sumRootToLeaf(root *TreeNode) int {
	num := 0
	dfsSumRootToLeaf(root, 0, &num)
	return num
}

func dfsSumRootToLeaf(root *TreeNode, a int, b *int) {
	if root == nil {
		return
	}
	a = a*2 + root.Val
	if root.Left == nil && root.Right == nil {
		*b += a
	}
	dfsSumRootToLeaf(root.Left, a, b)
	dfsSumRootToLeaf(root.Right, a, b)
}
```
