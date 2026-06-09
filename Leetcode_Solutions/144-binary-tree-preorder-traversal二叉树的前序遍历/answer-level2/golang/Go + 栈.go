```
func preorderTraversal(root *TreeNode) (rst []int) {
	if root == nil {
		return nil
	}
	var stack = list.New()
	stack.PushBack(root.Right)
	stack.PushBack(root.Left)

	rst = append(rst, root.Val)
	for stack.Len() != 0 {
		e := stack.Back()
		stack.Remove(e)
		node := e.Value.(*TreeNode)
		if node == nil {
			continue
		}
		rst = append(rst, node.Val)
		stack.PushBack(node.Right)
		stack.PushBack(node.Left)
	}
	return
}
```
