```
func convertBiNode(root *TreeNode) *TreeNode {
	lists := &TreeNode{}
	head := lists
	var (
		stack []*TreeNode
	)
	for root != nil || len(stack) != 0 {
		for root != nil {
			stack = append(stack, root)
			root = root.Left
			continue
		}
		pop := stack[len(stack)-1]
		stack = stack[:len(stack)-1]
		pop.Left = nil
		lists.Right = pop
		lists = pop
		root = pop.Right
	}
	return head.Right
}
```

```
//参考解题
func convertBiNode(root *TreeNode) *TreeNode {
	newList := &TreeNode{}
	head := newList
	var stack []*TreeNode
	for root != nil || len(stack) != 0 {
		if root != nil {
			stack = append(stack, root)
			root = root.Left
		} else {
			pop := stack[len(stack)-1]
			stack = stack[:len(stack)-1]
			pop.Left = nil
			newList.Right = pop
			newList = pop
			root = pop.Right
		}
	}
	return head.Right
}
```
