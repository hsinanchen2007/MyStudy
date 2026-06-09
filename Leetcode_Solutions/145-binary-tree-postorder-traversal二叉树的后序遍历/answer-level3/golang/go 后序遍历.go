```
//栈
func postorderTraversal(root *TreeNode) []int {
	if root == nil {
		return []int{}
	}
	nums, stack := make([]int, 0), make([]*TreeNode, 0)
	stack = append(stack, root)
	for len(stack) != 0 {
		node := stack[len(stack)-1]
		stack = stack[:len(stack)-1]
		nums = append([]int{node.Val}, nums...)
		if node.Left != nil {
			stack = append(stack, node.Left)
		}
		if node.Right != nil {
			stack = append(stack, node.Right)
		}
	}
	return nums
}
```
