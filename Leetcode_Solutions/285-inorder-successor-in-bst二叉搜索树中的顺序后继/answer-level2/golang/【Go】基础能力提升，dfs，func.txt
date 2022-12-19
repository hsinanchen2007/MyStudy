1.标记出p点，
2.使用中序遍历下一个节点就是目标
```
func inorderSuccessor(root *TreeNode, p *TreeNode) *TreeNode {
	if root == nil || p == nil {
		return nil
	}
	return nextNode(root, p)
}

func nextNode(root *TreeNode, p *TreeNode) *TreeNode {
	matched := false
	var result *TreeNode = nil
	var dfs func(node *TreeNode) bool
	dfs = func(node *TreeNode) bool {
		if node.Left != nil {
			if dfs(node.Left) {
				return true
			}
		}

		if matched {
			result = node
			return true
		}
		if node.Val == p.Val {
			matched = true
		}

		if node.Right != nil {
			if dfs(node.Right) {
				return true
			}
		}
		return false
	}

	dfs(root)
	return result
}
```
