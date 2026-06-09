```
func hight(root *TreeNode) int {
	if root == nil {
		return -1
	}
	return 1 + int(math.Max(float64(hight(root.Left)), float64(hight(root.Right))))
}

func isBalanced(root *TreeNode) bool {
	if root == nil {
		return true
	}
	return math.Abs(float64(hight(root.Left))-float64(hight(root.Right))) < 2 && isBalanced(root.Left) && isBalanced(root.Right)
}
```
