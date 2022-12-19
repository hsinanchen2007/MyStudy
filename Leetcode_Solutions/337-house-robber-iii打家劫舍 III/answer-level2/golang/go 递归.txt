```
type points struct {
	x, y int
}

func rob(root *TreeNode) int {
	res := dfsRob(root)
	return int(math.Max(float64(res.x), float64(res.y)))
}
func dfsRob(root *TreeNode) *points {
	res := &points{x: 0, y: 0}
	if root == nil {
		return res
	}
	left := dfsRob(root.Left)
	right := dfsRob(root.Right)
	res.x = int(math.Max(float64(left.x), float64(left.y))) + int(math.Max(float64(right.x), float64(right.y)))
	res.y = left.x + right.x + root.Val
	return res
}
```
