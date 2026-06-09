```
func buildTree(preorder []int, inorder []int) *TreeNode {
	if len(inorder) == 0 {
		return nil
	}
	idx := 0
	for k, v := range inorder {
		if v == preorder[0] {
			idx = k
			break
		}
	}
	root := &TreeNode{Val: preorder[0]}
	root.Left = buildTree(preorder[1:idx+1], inorder[0:idx])
	root.Right = buildTree(preorder[idx+1:], inorder[idx+1:])
	return root
}
```
