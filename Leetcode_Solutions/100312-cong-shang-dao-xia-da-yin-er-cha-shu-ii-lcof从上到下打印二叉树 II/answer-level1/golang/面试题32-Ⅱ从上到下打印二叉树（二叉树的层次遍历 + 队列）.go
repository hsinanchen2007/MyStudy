### 解题思路
二叉树的层次遍历 + 队列

### 代码

### 知识点：二叉树的层次遍历 + 队列

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
	if root == nil { // 特例处理
		return nil
	}
	
	res := make([][]int, 0)
	queue := make([]*TreeNode, 0) // 用切片模拟队列
	queue = append(queue, root) // 带root节点的初始队列
	for len(queue) != 0 { // 当队列不为空时，循环继续
		tmp := make([]int,0)
		queueLen := len(queue)
		for _, node := range queue { // 只需要循环当前层的节点数
			tmp = append(tmp, node.Val)
			if node.Left != nil {
				queue = append(queue, node.Left)
			}
			if node.Right != nil {
				queue = append(queue, node.Right)
			}
		}
		res = append(res, tmp)
		queue = queue[queueLen:] // 为下一层做准备
	}
	
	return res
}
```