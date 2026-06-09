```
func preorderTraversal(root *TreeNode) []int {
	nums := make([]int, 0)
	if root == nil {
		return nums
	}
	stack := make([]*TreeNode, 0)
	stack = append(stack, root)
	for len(stack) != 0 {
		node := stack[len(stack)-1]
		nums = append(nums, node.Val)
		stack = stack[0 : len(stack)-1]
		if node.Right != nil {
			stack = append(stack, node.Right)
		}
		if node.Left != nil {
			stack = append(stack, node.Left)
		}
	}
	return nums
}

```
