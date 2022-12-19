### 代码

```golang
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func minDepth(root *TreeNode) int {
	if root == nil {
		return 0
	}
	min := math.MaxInt64
	dfs(root, 1, &min)
	return min

}
func dfs(node *TreeNode, cur int, min *int) {
	if node.Left == nil && node.Right == nil {
		if cur < *min {
			*min = cur
		}
		return
	}
	if node.Left != nil {
		dfs(node.Left, cur+1, min)
	}
	if node.Right != nil {
		dfs(node.Right, cur+1, min)
	}
}
```