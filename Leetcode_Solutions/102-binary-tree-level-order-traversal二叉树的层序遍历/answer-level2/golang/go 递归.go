```
//递归
func levelOrder(root *TreeNode) [][]int {
	lists := make([][]int, 0)
	if root == nil {
		return lists
	}
	helper(root, &lists, 0)
	return lists
}

func helper(root *TreeNode, lists *[][]int, lens int) {
	if root == nil {
		return
	}
	if len(*lists) == lens {
		*lists = append(*lists, []int{})
	}
	(*lists)[lens] = append((*lists)[lens], root.Val)
	if root.Left != nil {
		helper(root.Left, lists, lens+1)
	}
	if root.Right != nil {
		helper(root.Right, lists, lens+1)
	}
}
```
