```
func isCousins(root *TreeNode, x int, y int) bool {
	var (
		a = make(map[int]int, 0)
		b = make(map[int]*TreeNode, 0)
	)
	dfsIsCousins(root, nil, &a, &b, 0)
	return a[x] == a[y] && b[x] != b[y]
}

func dfsIsCousins(root, pre *TreeNode, nums *map[int]int, p *map[int]*TreeNode, d int) {
	if root == nil {
		return
	}
	(*nums)[root.Val] = d
	(*p)[root.Val] = pre
	dfsIsCousins(root.Left, root, nums, p, d+1)
	dfsIsCousins(root.Right, root, nums, p, d+1)
}
```
