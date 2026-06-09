### 解题思路
dfs

### 代码

```golang
func sumEvenGrandparent(root *TreeNode) int {
	return dfs(root, false, false)
}

func dfs(node *TreeNode, prevEven bool, lastEven bool) int {
	if node == nil {
		return 0
	}
	res := 0
	if prevEven {
		res += node.Val
	}
	res += dfs(node.Left, lastEven, node.Val&1 == 0)
	res += dfs(node.Right, lastEven, node.Val&1 == 0)
	return res
}

```