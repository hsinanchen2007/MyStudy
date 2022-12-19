```
func longestUnivaluePath(root *TreeNode) int {
	num := 0
	help(root, &num)
	return num
}
func help(root *TreeNode, num *int) int {
	if root == nil {
		return 0
	}
	l := help(root.Left, num)
	r := help(root.Right, num)
	var al, ar int
	if root.Left != nil && root.Left.Val == root.Val {
		al = l + 1
	}
	if root.Right != nil && root.Right.Val == root.Val {
		ar += r + 1
	}
	*num = int(math.Max(float64(*num), float64(ar+al)))
	return int(math.Max(float64(al), float64(ar)))
}
```
