### 解题思路
# 递归深入，计算出左右深度后取最大值
# 注意边界值，树的深度可以为0

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

	if root.Left == nil && root.Right == nil {
		return 1
	}

	l := maxDepth(root.Left)
	r := maxDepth(root.Right)
	if l >= r {
		return l + 1
	}

	return r + 1
}
```