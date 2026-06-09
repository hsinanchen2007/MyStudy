### 解题思路
BFS，使用数组充当队列，每次计算出下次取出的结点数量

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
	results := [][]int{}
	// 每次循环次数
	tag := 1
	queue := []*TreeNode{}
	queue = append(queue, root)
	for tag != 0 {
		// 临时记录下次的循环次数
		temp := 0
		result := []int{}
		// 取出tag个结点
		for i := 0; i < tag; i++ {
			node := queue[0]
			queue = queue[1:]
			if node != nil {
				result = append(result, node.Val)
				queue = append(queue, node.Left, node.Right)
				temp += 2
				
			}
		}
		// 合并数组
		if len(result) != 0 {
			results = append(results, result)
		}
		tag = temp

	}
	return results
}

```