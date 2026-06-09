```
func minDepth(root *TreeNode) int {
	if root == nil {
		return 0
	}
	if (root.Left == nil) && (root.Right == nil) {
		return 1
	}
	min_Depth := math.MaxInt16
	if root.Left != nil {
		min_Depth = int(math.Min(float64(minDepth(root.Left)), float64(min_Depth)))
	}
	if root.Right != nil {
		min_Depth = int(math.Min(float64(minDepth(root.Right)), float64(min_Depth)))
	}
	return min_Depth + 1
}
```
