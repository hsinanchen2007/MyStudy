```golang
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func levelOrderBottom(root *TreeNode) [][]int {
	//广度优先搜索(bfs)
	result := [][]int{}
	if root == nil {
		return result
	}

	//初始化队列
    depth :=0

	qqq := []*TreeNode{root}
	 //队列长度(即当前层节点数)
	for length := 1;length > 0;length = len(qqq) {
		//从队列中取出当前层
		for i := 0; i < length; i++ {
			//出队
			node := qqq[0]
			qqq = qqq[1:]

			//值放入result
			if len(result) > depth {
				result[depth] = append(result[depth], node.Val)
			} else {
				result = append(result, []int{node.Val})
			}

			//下一层入队
			if node.Left != nil {
				qqq = append(qqq, node.Left)
			}
			if node.Right != nil {
				qqq = append(qqq, node.Right)
			}
		}
		depth++
	}

	//数组翻转
	resultLength := len(result)
	left := 0
	right := resultLength - 1
	for left < right {
		temp := result[left]
		result[left] = result[right]
		result[right] = temp
		left++
		right--
	}

	return result
}

```