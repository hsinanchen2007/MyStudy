```
func levelOrder(root *TreeNode) []int {
	if root == nil {
		return []int{}
	}
	nums, stack := make([]int, 0), make([]*TreeNode, 0)
	stack = append(stack, root)
	for len(stack) != 0 {
		node := stack[0]
		nums = append(nums, node.Val)
		if node.Left != nil {
			stack = append(stack, node.Left)
		}
		if node.Right != nil {
			stack = append(stack, node.Right)
		}
		stack = stack[1:]
	}

	return nums
}
```
