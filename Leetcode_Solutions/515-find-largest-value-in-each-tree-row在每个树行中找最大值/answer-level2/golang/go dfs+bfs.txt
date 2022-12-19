```
//dfs
func largestValues(root *TreeNode) []int {
	res := make([]int, 0)
	if root == nil {
		return res
	}

	dfsLargestValues(root, &res, 0)
	return res
}

func dfsLargestValues(root *TreeNode, res *[]int, level int) {
	if root == nil {
		return
	}
	if len(*res) == level {
		*res = append(*res, math.MinInt32)
	}
	(*res)[level] = int(math.Max(float64((*res)[level]), float64(root.Val)))
	if root.Left != nil {
		dfsLargestValues(root.Left, res, level+1)
	}
	if root.Right != nil {
		dfsLargestValues(root.Right, res, level+1)
	}
}
```
```
//bfs
func largestValues(root *TreeNode) []int {
	res := make([]int, 0)
	if root == nil {
		return res
	}
	stack := make([]*TreeNode, 0)
	stack = append(stack, root)
	for len(stack) != 0 {
		size := len(stack)
		levelMax := math.MinInt32
		for i := 0; i < size; i++ {
			curNode := stack[0]
			stack = stack[1:]
			levelMax = int(math.Max(float64(curNode.Val), float64(levelMax)))
			if curNode.Left != nil {
				stack = append(stack, curNode.Left)
			}
			if curNode.Right != nil {
				stack = append(stack, curNode.Right)
			}
		}
		res = append(res, levelMax)
	}
	return res
}
```

