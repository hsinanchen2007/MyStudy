```
//bfs
func findBottomLeftValue(root *TreeNode) int {
	if root.Left == nil && root.Right == nil {
		return root.Val
	}
	stack := make([]*TreeNode, 0)
	stack = append(stack, root)
	for len(stack) > 0 {
		root = stack[0]
		stack = stack[1:]
		if root.Right != nil {
			stack = append(stack, root.Right)
		}
		if root.Left != nil {
			stack = append(stack, root.Left)
		}
	}
	return root.Val
}
```
```
//dfs 耗时最少
func findBottomLeftValue(root *TreeNode) int {
	if root.Left == nil && root.Right == nil {
		return root.Val
	}
	val, maxLevel := 0, 0
	dfsFindBottomLeftValue(root, &val, &maxLevel, 0)
	return val
}
func dfsFindBottomLeftValue(root *TreeNode, val, maxLevel *int, level int) {
	if root == nil {
		return
	}
	dfsFindBottomLeftValue(root.Left, val, maxLevel, level+1)
	if level > *maxLevel {
		*maxLevel = level
		*val = root.Val
	}
	dfsFindBottomLeftValue(root.Right, val, maxLevel, level+1)
}
```
