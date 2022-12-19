```
func averageOfLevels(root *TreeNode) []float64 {
	var (
		queue []*TreeNode
		ans   []float64
		sum   int
	)
	a, b := 0, 1
	queue = append(queue, root)
	for len(queue) != 0 {
		tmp := queue[0]
		queue = queue[1:]
		a++
		sum += tmp.Val
		if tmp.Left != nil {
			queue = append(queue, tmp.Left)
		}
		if tmp.Right != nil {
			queue = append(queue, tmp.Right)
		}
		if a == b {
			ans = append(ans, float64(sum)/float64(b))
			sum = 0
			a = 0
			b = len(queue)
		}
	}
	return ans
}
```


```
//闭包
func averageOfLevels(root *TreeNode) []float64 {
	var (
		ans        []float64
		node, sum  []int
		getAverage func(root *TreeNode, sum, node []int, dep int) ([]int, []int)
	)
	if root == nil {
		return ans
	}
	getAverage = func(root *TreeNode, sum, node []int, deep int) (ints []int, ints2 []int) {
		if root == nil || (root.Left == nil && root.Right == nil) {
			return sum, node
		}
		if deep >= len(sum) {
			sum = append(sum, 0)
			node = append(node, 0)
		}
		if root.Left != nil {
			sum[deep] += root.Left.Val
			node[deep]++
		}
		if root.Right != nil {
			sum[deep] += root.Right.Val
			node[deep]++
		}
		sum, node = getAverage(root.Left, sum, node, deep+1)
		sum, node = getAverage(root.Right, sum, node, deep+1)
		return sum, node
	}
	sum = append(sum, root.Val)
	node = append(node, 1)
	sum, node = getAverage(root, sum, node, 1)
	for i := 0; i < len(sum); i++ {
		ans = append(ans, float64(sum[i])/float64(node[i]))
	}
	return ans
}
```

```
func averageOfLevels(root *TreeNode) []float64 {
	var (
		curl, nextl []*TreeNode
		ans         []float64
	)
	curl = append(curl, root)
	for len(curl) > 0 {
		sum := 0
		for i := 0; i < len(curl); i++ {
			sum += curl[i].Val
			if curl[i].Left != nil {
				nextl = append(nextl, curl[i].Left)
			}
			if curl[i].Right != nil {
				nextl = append(nextl, curl[i].Right)
			}
		}
		ans = append(ans, float64(sum)/float64(len(curl)))
		curl = nextl[:]
		nextl = []*TreeNode{}
	}
	return ans
}
```

