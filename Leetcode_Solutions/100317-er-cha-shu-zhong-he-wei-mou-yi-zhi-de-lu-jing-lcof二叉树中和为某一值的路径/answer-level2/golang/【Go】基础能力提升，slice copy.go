```
func pathSum(root *TreeNode, sum int) [][]int {
	if root == nil {
		return nil
	}

	result := make([][]int, 0)
	target := 0
	path := make([]int, 0)
	var dfs func(node *TreeNode)
	dfs = func(node *TreeNode) {
		target += node.Val
		path = append(path, node.Val)
		//fmt.Printf("target: %d, val: %d\r\n", target, node.Val)
		if target == sum && node.Left == nil && node.Right == nil {
			//fmt.Printf("bingo\r\n")
			validPath := make([]int, len(path))
			copy(validPath, path)
			result = append(result, validPath)
		}

		if node.Left != nil {
			dfs(node.Left)
			target -= node.Left.Val
			path = path[0 : len(path) - 1]
		}

		if node.Right != nil {
			dfs(node.Right)
			target -= node.Right.Val
			path = path[0 : len(path) - 1]
		}
	}

	dfs(root)
	return result
}
```
