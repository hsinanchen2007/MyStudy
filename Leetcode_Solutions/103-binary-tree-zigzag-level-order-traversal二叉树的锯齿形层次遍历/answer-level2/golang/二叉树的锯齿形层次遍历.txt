### 解题思路
栈

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
func zigzagLevelOrder(root *TreeNode) [][]int {
	if root == nil {
		return nil
	}
	res := make([][]int, 0)
	stack := make([]*TreeNode, 0, 16)
	stack = append(stack, root)
	f := true
	for len(stack) > 0{
		size := len(stack)
		nextStack := make([]*TreeNode, 0, size)
		values := make([]int, 0, size)
		for i:=size-1; i >= 0; i-- {
			node := stack[i]
			values = append(values, node.Val)
			if f {
				if node.Left!=nil {
					nextStack = append(nextStack, node.Left)
				}
				if node.Right!= nil {
					nextStack = append(nextStack, node.Right)
				}
			} else {
				if node.Right!=nil {
					nextStack = append(nextStack, node.Right)
				}
				if node.Left != nil {
					nextStack = append(nextStack, node.Left)
				}
			}
		}
		f = !f
		res = append(res, values)
		stack = nextStack
	}
	return res
}




```