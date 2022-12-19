```
//1、dfs解法
func zigzagLevelOrder(root *TreeNode) [][]int {
	res := make([][]int, 0)
	if root == nil {
		return res
	}
	DFs(root, &res, 0)
	return res
}

func DFs(root *TreeNode, nums *[][]int, n int) {
	if n >= len(*nums) {
		*nums = append(*nums, []int{root.Val})
	} else {
		if n%2 == 0 {
			(*nums)[n] = append((*nums)[n], root.Val)
		} else {
			(*nums)[n] = append([]int{root.Val}, (*nums)[n]...)
		}
	}

	if root.Left != nil {
		DFs(root.Left, nums, n+1)
	}
	if root.Right != nil {
		DFs(root.Right, nums, n+1)
	}
}
```

```
//参考的bfs


func zigzagLevelOrder(root *TreeNode) [][]int {
	if root == nil {
		return nil
	}
	var res = [][]int{}
	var queue = []*TreeNode{root}
	var level, counter, knife, cur int
	for len(queue) > 0 {
		counter = len(queue)
		knife = counter
		res = append(res, []int{})
		for 0 < counter {
			cur = knife - counter
			if queue[cur].Left != nil {
				queue = append(queue, queue[cur].Left)
			}
			if queue[cur].Right != nil {
				queue = append(queue, queue[cur].Right)
			}

			counter--
			if level%2 != 0 {
				cur = counter
			}
			res[level] = append(res[level], queue[cur].Val)
		}
		queue = queue[knife:]
		level++
	}
	return res
}
```

