极简单的递归使用

```go
func inorderTraversal(root *TreeNode) []int {
	if root == nil {
		return nil
	}
	r1 := inorderTraversal(root.Left)
	r2 := inorderTraversal(root.Right)
	return append(append(r1, root.Val), r2...)
}
```
