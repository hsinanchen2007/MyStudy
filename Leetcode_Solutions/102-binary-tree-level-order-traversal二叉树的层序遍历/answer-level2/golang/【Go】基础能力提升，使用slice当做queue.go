```
func levelOrder(root *TreeNode) [][]int {
	if root == nil {
		return make([][]int, 0)
	}

	result := make([][]int, 0)
	return bfs(root, result)
}

func bfs(root *TreeNode, result [][]int) [][]int {
	rowData := make([]int, 0)
	queue := make([]*TreeNode, 0)
	queue = append(queue, root)
	for {
		count := len(queue)
		rowData = make([]int, 0)
		if count > 0 {
			for _, node := range queue {
				if node != nil {
					rowData = append(rowData, node.Val)
					if node.Left != nil {
						queue = append(queue, node.Left)
					}
					if node.Right != nil {
						queue = append(queue, node.Right)
					}
				}
			}
			result = append(result, rowData)
			queue = queue[count:]
			continue
		}
		break
	}
	return result
}

```
