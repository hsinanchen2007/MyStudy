```
var result []int = make([]int, 0)

func inorderTraversalData(root *TreeNode) {
	if root == nil {
		return
	}
	inorderTraversalData(root.Left)
	result = append(result, root.Val)
	inorderTraversalData(root.Right)
}
func inorderTraversal(root *TreeNode) []int {
	result = result[0:0]
	if root == nil {
		return result
	}
	inorderTraversalData(root)
	return result
}
```
