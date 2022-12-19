### 解题思路
递归

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

func isUnivalTree(root *TreeNode) bool {

	v := root.Val

	return comp(root, v)
}

func comp(root *TreeNode, v int) bool {

	if root == nil {
		return true
	}

	if root.Val != v {
		return false
	}

	return comp(root.Left, v) && comp(root.Right, v)
}


```