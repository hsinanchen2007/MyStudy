```
func isBalanced(root *TreeNode) bool {
	return dfsIsBalanced(root) != -1
}

func dfsIsBalanced(root *TreeNode) int {
	if root == nil {
		return 0
	}
	l := dfsIsBalanced(root.Left)
	r := dfsIsBalanced(root.Right)
	if l != -1 && r != -1 && int(math.Abs(float64(l-r))) <= 1 {
		return int(math.Max(float64(l), float64(r))) + 1
	}
	return -1
}
```


```
//另外一种答题
func hight(root *TreeNode) int {
	if root == nil {
		return -1
	}
	return 1 + int(math.Max(float64(hight(root.Left)), float64(hight(root.Right))))
}

func isBalanced(root *TreeNode) bool {
	if root == nil {
		return true
	}
	return math.Abs(float64(hight(root.Left))-float64(hight(root.Right))) < 2 && isBalanced(root.Left) && isBalanced(root.Right)
}

```

