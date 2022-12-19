golang 0 ms 2.9MB 
队列实现 BFS，改良的一点是：不用反复计算队列的长度以及对队列进行出队操作。通过前后指针来实现，缺点是如果节点非常多，队列会占用较大空间，属于空间换时间的行为
```
func levelOrder(root *TreeNode) [][]int {
	var q []*TreeNode
	var result [][]int
	if root == nil {return result}
	q = append(q, root)
	left, right := 0, 1
	for left < right {
		tmp := make([]int, right-left)
		rightNew := right
		start := left
		for left < right {
			tmp[left - start] = q[left].Val
			if q[left].Left != nil { q = append(q, q[left].Left); rightNew += 1}
			if q[left].Right != nil {q = append(q, q[left].Right); rightNew += 1}
			left += 1
		}
		right = rightNew
		result = append(result, tmp)
	}
	return result
}

```
