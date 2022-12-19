```golang []
func GetMax(root *TreeNode) int {
	if root == nil {
		return 0
	}
	return int(math.Max(float64(GetMax(root.Right)),float64(GetMax(root.Left)))) + 1
}

func isBalanced(root *TreeNode) bool {
    if root == nil {
		return true
	}
    return math.Abs(float64(GetMax(root.Left))-float64(GetMax(root.Right))) <= 1 && isBalanced(root.Left) && isBalanced(root.Right)
}
```



