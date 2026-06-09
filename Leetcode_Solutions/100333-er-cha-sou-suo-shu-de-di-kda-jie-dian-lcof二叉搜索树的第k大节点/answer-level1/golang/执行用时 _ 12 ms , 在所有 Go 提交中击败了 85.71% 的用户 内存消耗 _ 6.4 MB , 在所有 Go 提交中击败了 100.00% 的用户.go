### 解题思路


常规思路 中序遍历

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
func kthLargest(root *TreeNode, k int) int {
if root == nil {
		return 0
	}

	var stack []*TreeNode
	count := 0
	curNode := root
	var res []int

	for curNode != nil || len(stack) > 0 {
		if curNode != nil {
			stack = append(stack, curNode)
			curNode = curNode.Left
			continue
		}

		node := stack[len(stack)-1]
		res = append(res, node.Val)
		stack = stack[:len(stack)-1]
		curNode = node.Right
		count++
	}
	return res[len(res)-k]

}
```