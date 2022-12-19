golang里面没有直接提供queue，可以通过一个slice来模拟，遍历完每一层统计结果
```
func averageOfLevels(root *TreeNode) []float64 {
	queue := make([]*TreeNode, 0)
	queue = append(queue, root)
	first, last := 0, 1
	res := make([]float64, 0)
	sum := 0
	for len(queue) != 0 {
		tmp := queue[0]
		queue = queue[1:]
		first++

		sum += tmp.Val
		if tmp.Left != nil {
			queue = append(queue, tmp.Left)
		}
		if tmp.Right != nil {
			queue = append(queue, tmp.Right)
		}

		if first == last {
			res = append(res, float64(sum)/float64(last))
			sum = 0
			first = 0
			last = len(queue)
		}
	}
	return res
}
```