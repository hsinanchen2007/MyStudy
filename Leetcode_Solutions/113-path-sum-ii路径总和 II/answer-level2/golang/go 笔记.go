```
func pathSum(root *TreeNode, sum int) [][]int {
	res := make([][]int, 0)
	DFS(root, sum, []int{}, &res)
	return res
}
func DFS(root *TreeNode, sum int, stack []int, res *[][]int) {
	if root == nil {
		return
	}
	stack = append(stack, root.Val)
	if root.Left == nil && root.Right == nil {
		if sum == root.Val {
			r := make([]int, len(stack))
			copy(r, stack)
			*res = append(*res, r)
		}
	}
	DFS(root.Left, sum-root.Val, stack, res)
	DFS(root.Right, sum-root.Val, stack, res)
}
```
