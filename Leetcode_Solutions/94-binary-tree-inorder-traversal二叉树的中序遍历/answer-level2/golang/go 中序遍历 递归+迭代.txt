```
//递归
func inorderTraversal(root *TreeNode) []int {
	helper := make([]int, 0)
	dfsinorderTraversal(root, &helper)
	return helper
}
func dfsinorderTraversal(root *TreeNode, helper *[]int) {
	if root == nil {
		return
	}
	if root.Left != nil {
		dfsinorderTraversal(root.Left, helper)
	}
	*helper = append(*helper, root.Val)
	if root.Right != nil {
		dfsinorderTraversal(root.Right, helper)
	}
}
```

```
//迭代
func inorderTraversal(root *TreeNode) []int {
	nums := make([]int, 0)
	stack := []*TreeNode{}
	for root != nil || len(stack) != 0 {
		for root != nil {
			stack = append(stack, root)
			root = root.Left
		}
		nums = append(nums, stack[len(stack)-1].Val)
		root = stack[len(stack)-1].Right
		stack = stack[:len(stack)-1]
	}
	return nums
}
```

