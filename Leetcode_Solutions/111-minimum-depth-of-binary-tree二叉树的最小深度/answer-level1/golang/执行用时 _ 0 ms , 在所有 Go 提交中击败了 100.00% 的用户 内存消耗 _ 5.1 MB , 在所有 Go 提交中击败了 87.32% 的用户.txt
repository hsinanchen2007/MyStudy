### 解题思路

BFS

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
	min := 0

	if root == nil {
		return min
	}
	var queue []*TreeNode

	queue = append(queue, root)
	for len(queue) > 0 {
		qLen := len(queue)
		min++
		for i := 0; i < qLen; i++ {
			if queue[i].Right == nil && queue[i].Left == nil {
				return min
			}

			if queue[i].Left != nil {
				queue = append(queue, queue[i].Left)
			}
			if queue[i].Right != nil {
				queue = append(queue, queue[i].Right)
			}
		}
		queue = queue[qLen:]
	}

	return min
}
```