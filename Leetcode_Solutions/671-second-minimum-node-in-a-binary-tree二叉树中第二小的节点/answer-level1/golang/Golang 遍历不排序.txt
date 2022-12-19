

```

func findSecondMinimumValue(root *TreeNode) int {
	if root == nil {
		return -1
	}
	return find(root,root.Val)

}

func find(node *TreeNode,min int) int {
	if node == nil {
		return -1
	}
	if node.Val > min {
		return node.Val
	}
	left := find(node.Left,min)
	right := find(node.Right,min)
	if left == -1 {
		return right
	}
	if right == -1 {
		return left
	}

	return int(math.Min(float64(right),float64(left)))

}
```
