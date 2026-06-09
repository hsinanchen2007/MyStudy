// ### 解题思路

// 感谢素未谋面, ❤❤💖💖✔✔，[我的老师**花花酱**视频讲解](http://zxi.mytechroad.com/blog/leetcode/leetcode-102-binary-tree-level-order-traversal/), 在他的博客里面，还介绍了使用DFS来解答这题的方法。

// 逐层遍历树，使用Queue的概念就行，**先进先出**。

// 对于一棵树，我们先把根节点enque。

// 只要这个queue里面不为空：
//     此时 queue的长度就是当前层级 level 的节点数。
//     dequeue出第一个元素，把值放在结果里面，表示这个节点已经访问过了。
//     对于这个节点，把他的两个子节点按照先左，后右 enqueue。


// ### 例子

// ```
    3
   / \
  9  20
    /  \
   15   7
// ```

// 0.  queue = [], result=[]
// 1.  queue = [3]
//     1.  nodeCount = 1, node = 3, level = []
//     2.  queue = [9, 20], level = [3]
//     3.  nodeCount = 0, result = [[3]]
// 2.  queue = [9, 20]
//     1.  nodeCount = 2, node = 9, level = [9]
//     2.  nodeCount = 1, node = 20, level = [9, 20]
//     3.  enque, queue=[15,7],
//     4.  nodeCount = 0, result = [[3], [9, 20]]

// 重复之后就得到：
//     queue = []
//     result = [[3],[9.20],[15,7]]

//     -   逐层遍历其实就是Graph 里面用BFS（广度优先搜索）来探索图，题目都是按照层次遍历，运用Queue的概念。
//     -   而DFS（深度优先搜素）采用的是Stack（现金后出）的概念。
//     牢记这两点。

// ### 代码

// ```golang
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func levelOrder(root *TreeNode) [][]int {
	result := make([][]int, 0)
	if root == nil {
		return result
	}
	// Create a queue.
	queue := make([]*TreeNode, 0)
	// Enqueue the root note
	queue = append(queue, root)

	for len(queue) > 0 {
		// Get the nodeCount in the queue,
		// which is also the nodeCount in current level
		nodeCount := len(queue)
		level := make([]int, 0)
		// Dequeue all nodes from the current level
		// Enqueue all nodes of the next level
		for nodeCount > 0 {
			node := queue[0]
			level = append(level, node.Val)
			queue = queue[1:]
			if node.Left != nil {
				queue = append(queue, node.Left)
			}
			if node.Right != nil {
				queue = append(queue, node.Right)
			}
			nodeCount--
		}
		result = append(result, level)
	}
	return result
}
// ```