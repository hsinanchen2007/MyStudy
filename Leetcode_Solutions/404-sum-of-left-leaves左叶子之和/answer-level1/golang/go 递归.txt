```
//递归解法
func dfs(root *TreeNode, sum *int,isLeft int) {
	if root == nil {
		return
	}
	dfs(root.Left, sum,1)
	if root.Left == nil && root.Right == nil && isLeft == 1 {
		*sum += root.Val
	}
	dfs(root.Right, sum,2)
}
func sumOfLeftLeaves(root *TreeNode) int {
	if root == nil {
		return 0
	}
	sum := 0
	dfs(root, &sum,0)
	return sum
}

//另外的递归
func sumOfLeftLeaves(root *TreeNode) int {
	if root == nil {
		return 0
	}
	if root.Left != nil && root.Left.Left == nil && root.Left.Right == nil {
		return root.Left.Val + sumOfLeftLeaves(root.Right)
	}
	return sumOfLeftLeaves(root.Left) + sumOfLeftLeaves(root.Right)
}

```
