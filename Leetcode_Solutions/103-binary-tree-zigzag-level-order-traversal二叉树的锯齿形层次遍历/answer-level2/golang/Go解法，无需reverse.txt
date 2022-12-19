>执行用时 :0 ms, 在所有 Go 提交中击败了100.00%的用户
	
>内存消耗 :3 MB, 在所有 Go 提交中击败了97.01%的用户

```go
func zigzagLevelOrder(root *TreeNode) [][]int {
	if root == nil {
		return nil
	}

	var result [][]int

	needReverse := true
	nodes := []*TreeNode{root}
	for len(nodes) != 0 {
		result = append(result, extractVal(nodes))
		nodes = levelNodes(nodes, needReverse)
		needReverse = !needReverse
	}
	return result
}

func extractVal(in []*TreeNode) []int {
	val := make([]int, len(in))
	for i := 0; i < len(in); i++ {
		val[i] = in[i].Val
	}
	return val
}

func levelNodes(in []*TreeNode, needReverse bool) (result []*TreeNode) {
	if needReverse {
		for i := len(in)-1; i >=0;i--{
			node := in[i]
			if node.Right != nil {
				result = append(result, node.Right)
			}
			if node.Left != nil {
				result = append(result, node.Left)
			}
		}
		return
	}
	for i := len(in)-1; i >=0;i--{
		node := in[i]
		if node.Left != nil {
			result = append(result, node.Left)
		}
		if node.Right != nil {
			result = append(result, node.Right)
		}
	}
	return
}
```