```
func findSecondMinimumValue(root *TreeNode) int {
	return dfsmin(root, root.Val)
}
func dfsmin(root *TreeNode, val int) int {
	if root == nil {
		return -1
	}
	if root.Val > val {
		return root.Val
	}

	sleft := dfsmin(root.Left, val)
	sright := dfsmin(root.Right, val)
	if sleft == -1 {
		return sright
	}
	if sright == -1 {
		return sleft
	}
	return int(math.Min(float64(sleft), float64(sright)))
}
```
