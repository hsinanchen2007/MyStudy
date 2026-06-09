```
//中序遍历
func isValidBST(root *TreeNode) bool {
	inorder := math.MinInt64
	stack := []*TreeNode{}
	for root != nil || len(stack) != 0 {
		for root != nil {
			stack = append(stack, root)
			root = root.Left
		}
		if inorder >= stack[len(stack)-1].Val {
			return false
		}
		inorder = stack[len(stack)-1].Val
		root = stack[len(stack)-1].Right
		stack = stack[:len(stack)-1]
	}
	return true
}

```

```
//递归
func isValidBST(root *TreeNode) bool {
	return dfsisValidBST(root, math.MinInt64, math.MaxInt64)
}

func dfsisValidBST(root *TreeNode, low, up int) bool {
	return root == nil || low < root.Val && root.Val < up && dfsisValidBST(root.Left, low, root.Val) && dfsisValidBST(root.Right, root.Val, up)
}
```

