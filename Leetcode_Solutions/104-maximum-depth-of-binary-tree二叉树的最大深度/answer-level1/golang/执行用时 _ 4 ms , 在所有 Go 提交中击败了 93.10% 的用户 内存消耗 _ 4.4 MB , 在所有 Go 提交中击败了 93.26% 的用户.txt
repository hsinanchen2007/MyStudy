### 解题思路

按层的概念，一层层拨

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
		depth := 0
	if root == nil {
		return 0
	}
	var queue []*TreeNode

	queue = append(queue, root)

	for len(queue) > 0 {
		qLen := len(queue)
		for i := 0; i < qLen; i++ {
			left := queue[i].Left
			right := queue[i].Right
			if left != nil {
				queue = append(queue, left)
			}

			if right != nil {
				queue = append(queue, right)
			}
		}
		queue = queue[qLen:]
		depth++
	}

	return depth
}
```