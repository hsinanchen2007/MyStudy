### 解题思路
递归 比较左右子树深度 取最大值+1

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
func maxDepth(root *TreeNode) int {
	if root == nil {
		return 0
	}
	left := maxDepth(root.Right)
	right := maxDepth(root.Left)
	if left > right {
		return left + 1
	}
	return right + 1
}
```