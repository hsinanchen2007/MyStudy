```
func maxDepth(root *Node) int {
	if root == nil {
		return 0
	}
	max := 0
	for _, v := range root.Children {
		depth := maxDepth(v)
		max = int(math.Max(float64(max), float64(depth)))
	}
	return max + 1
}
```
