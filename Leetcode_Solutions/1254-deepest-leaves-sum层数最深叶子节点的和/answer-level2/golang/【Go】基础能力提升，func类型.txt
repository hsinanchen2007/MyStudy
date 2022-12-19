```
func deepestLeavesSum(root *TreeNode) int {
	var dfs func(node *TreeNode, level int)
	maxLevel := 0
	sum := 0
	dfs = func(node *TreeNode, level int) {
		if node == nil {
			return
		}
		if maxLevel < level {
			maxLevel = level
			sum = node.Val
		} else if maxLevel == level{
			sum += node.Val
		} 
		
		dfs(node.Left, level + 1)
		dfs(node.Right, level + 1)
	}
	
	dfs(root, 1)
	return  sum
}
```
