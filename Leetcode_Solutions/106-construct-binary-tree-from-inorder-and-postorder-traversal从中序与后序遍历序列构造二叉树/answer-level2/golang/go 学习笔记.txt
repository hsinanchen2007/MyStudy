```
func buildTree(inorder []int, postorder []int) *TreeNode {
	l := len(postorder) - 1
	for k, v := range inorder {
		if inorder[k] == postorder[l] {
			return &TreeNode{
				Val:   v,
				Left:  buildTree(inorder[:k], postorder[:k]),
				Right: buildTree(inorder[k+1:], postorder[k:l]),
			}
		}
	}
	return nil
}
```
