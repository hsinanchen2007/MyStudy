```
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
	// 创建一个队列，并将根节点入队
	queue := []*TreeNode{root}
	depth := 0
	for len(queue) > 0 {
		size := len(queue)
		// 将该层的节点出队
		for i := 0; i < size; i++ {
			// 获取该节点
			node := queue[0]
			// 该节点出队
			queue = queue[1:]
			// 入队
			if node.Left != nil {
				queue = append(queue, node.Left)
			}
			if node.Right != nil {
				queue = append(queue, node.Right)
			}
		}
		depth++
	}
	return depth
}
```

