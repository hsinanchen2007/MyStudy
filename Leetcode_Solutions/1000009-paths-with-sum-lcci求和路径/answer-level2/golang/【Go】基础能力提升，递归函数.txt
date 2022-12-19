```
func pathSum(root *TreeNode, sum int) int {
	if root == nil {
		return 0
	}

	result := 0
	var dfs func(node *TreeNode)
	dfs = func(node *TreeNode) {
		result += pathSumUp2Down(sum, node)
		if node.Left != nil {
			dfs(node.Left)
		}
		if node.Right != nil {
			dfs(node.Right)
		}
	}
	dfs(root)
	return result
}

func pathSumUp2Down(sum int, root *TreeNode) int {
	result := 0
	target := 0
	var dfs func(node *TreeNode)
	dfs = func(node *TreeNode) {
		target += node.Val
		if target == sum {
			result++
		}

		if node.Left != nil {
			dfs(node.Left)
			target -= node.Left.Val
		}
		if node.Right != nil {
			dfs(node.Right)
			target -= node.Right.Val
		}
	}

	dfs(root)
	return result
}
```
