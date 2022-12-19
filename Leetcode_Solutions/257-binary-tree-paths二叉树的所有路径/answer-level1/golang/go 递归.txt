```
//dfs 递归
func binaryTreePaths(root *TreeNode) []string {
	if root == nil {
		return []string{}
	}
	ss := []string{}
	dfs(root, "", &ss)
	return ss
}

func dfs(root *TreeNode, path string, ss *[]string) {
	if root != nil {
		path += strconv.Itoa(root.Val)
		if (root.Left == nil) && (root.Right == nil) {
			*ss = append(*ss, path)
		} else {
			path += "->"
			dfs(root.Left, path, ss)
			dfs(root.Right, path, ss)
		}
	}
}
```
