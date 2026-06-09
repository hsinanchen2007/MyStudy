### 解题思路
基于栈

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
func inorderTraversal(root *TreeNode) []int {
	stack := make([]*TreeNode, 0, 16)
	res := make([]int, 0, 16)
	node := root
	for node != nil || len(stack) > 0 {
		for node != nil {
			stack = append(stack, node)
			node = node.Left
		}
		l := len(stack) - 1
		node = stack[l]
		stack = stack[0:l]
		res = append(res, node.Val)
		node = node.Right
	}
	return res
}
```