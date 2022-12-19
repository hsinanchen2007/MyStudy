### 解题思路
二叉树广度优先搜索(BFS)：用队列完成二叉树层次遍历

### 知识点：二叉树BFS + 队列

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
func levelOrder(root *TreeNode) []int {
	// 二叉树BFS
	if root == nil {
		return nil
	}

	// 结果数组
	res := make([]int, 0)  // var res []int
	// 根节点入队列
	// 用切片模拟队列
	queue := []*TreeNode{root} // queue := make([]*TreeNode, 0)
	// 队列不为空
	for len(queue) != 0 {
		res = append(res, queue[0].Val)
		if queue[0].Left != nil {
			queue = append(queue, queue[0].Left) // 模拟队列的入栈
		}
		if queue[0].Right != nil {
			queue = append(queue, queue[0].Right)
		}
		queue = queue[1:]  // 模拟队列的弹出
	}
	return res
}
```