```
func countNodes(root *TreeNode) int {
	sum := 0
	helperCountNodes(root, &sum)
	return sum
}
func helperCountNodes(root *TreeNode, sum *int) {
	if root == nil {
		return
	}
	*sum += 1
	helperCountNodes(root.Left, sum)
	helperCountNodes(root.Right, sum)
}
```
