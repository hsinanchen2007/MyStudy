### 解题思路

按层的概念去处理

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
func averageOfLevels(root *TreeNode) []float64 {
		var ary []float64
	var queue []*TreeNode

	queue = append(queue, root)
	for len(queue) > 0 {
		sLen := len(queue)
		sum := 0
		for i := 0; i < sLen; i++ {
			sum += queue[i].Val
			if queue[i].Left != nil {
				queue = append(queue, queue[i].Left)
			}
			if queue[i].Right != nil {
				queue = append(queue, queue[i].Right)
			}
		}
		queue = queue[sLen:]
		ary = append(ary, float64(sum)/float64(sLen))
	}

	return ary
}
```