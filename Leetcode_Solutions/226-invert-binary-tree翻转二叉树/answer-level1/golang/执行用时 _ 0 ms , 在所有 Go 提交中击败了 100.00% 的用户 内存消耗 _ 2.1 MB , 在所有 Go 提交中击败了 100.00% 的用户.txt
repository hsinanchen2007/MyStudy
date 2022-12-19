### 解题思路

1.看叶节点：1 3 6 9 交换后 3 1 9 6。
2.看该叶节点的上一个节点 7 2 交换后 2  7 同时 下面的页节点就变成 9 6 3 1


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
func invertTree(root *TreeNode) *TreeNode {
	if root == nil {
		return root
	}

	left := invertTree(root.Left)
	right := invertTree(root.Right)

	root.Left = right
	root.Right = left

	return root
}
```