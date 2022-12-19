```
func isValidBST(root *TreeNode) bool {
	if root == nil{
		return true
	}

	data := make([]int, 0)
	var dfs func(node *TreeNode) bool
	dfs = func(node *TreeNode) bool {
		if node.Left != nil {
			if !dfs(node.Left) {
				return false
			}
		}

		if len(data) == 0 {
			data = append(data, node.Val)
		} else if node.Val > data[len(data) - 1] {
			data = append(data, node.Val)
		} else {
			return false
		}
		if node.Right != nil {
			if !dfs(node.Right) {
				return false
			}
		}
		return true
	}
	return dfs(root)
}
```
