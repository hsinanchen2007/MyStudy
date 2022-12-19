```
func kthLargest(root *TreeNode, k int) int {
	count := make([]int, 0)
	dfskthLargest(root, &count)
	return count[k-1]
}

func dfskthLargest(root *TreeNode, count *[]int) {
	if root.Right != nil {
		dfskthLargest(root.Right, count)
	}
	if root != nil {
		*count = append(*count, root.Val)
	}
	if root.Left != nil {
		dfskthLargest(root.Left, count)
	}
}
```


```
//go 迭代
func kthLargest(root *TreeNode, k int) int {
	if root == nil {
		return 0
	}
	var (
		stack []*TreeNode
		count int
		node  = root
		nums  []int
	)
	for node != nil || len(stack) > 0 {
		if node != nil {
			stack = append(stack, node)
			node = node.Left
			continue
		}
		nodes := stack[len(stack)-1]
		nums = append(nums, nodes.Val)
		stack = stack[:len(stack)-1]
		node = nodes.Right
		count++
	}
	return nums[len(nums)-k]
}
```

