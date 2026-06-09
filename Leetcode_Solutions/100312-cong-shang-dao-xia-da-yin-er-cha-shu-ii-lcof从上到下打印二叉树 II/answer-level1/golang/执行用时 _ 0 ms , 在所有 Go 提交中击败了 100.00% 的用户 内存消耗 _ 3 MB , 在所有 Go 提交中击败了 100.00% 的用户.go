### 解题思路
此处撰写解题思路

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
func levelOrder(root *TreeNode) [][]int {
		var ret [][]int
	var queue [] TreeNode

	if root == nil {
		return ret
	}

	queue = append(queue, *root)

	for len(queue) > 0 {
		var tmp []int
		queueLen := len(queue)
		for i := 0; i < queueLen; i++ {
			node := queue[i]
			tmp = append(tmp, node.Val)
			if node.Left != nil {
				queue = append(queue, *node.Left)
			}

			if node.Right != nil {
				queue = append(queue, *node.Right)
			}
		}
		queue = queue[queueLen:]
		ret = append(ret, tmp)
	}

	return ret
}
```