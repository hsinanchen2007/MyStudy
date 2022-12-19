```
func levelOrder(root *TreeNode) [][]int {
	var (
		r [][]int
		a []*TreeNode
	)
	if root == nil {
		return r
	}
	a = append(a, root)
	for len(a) > 0 {
		var tmp []int
		num := len(a)
		for i := 0; i < num; i++ {
			node := a[0]
			tmp = append(tmp, node.Val)
			if node.Left != nil {
				a = append(a, node.Left)
			}
			if node.Right != nil {
				a = append(a, node.Right)
			}
			a = a[1:]
		}
		r = append(r, tmp)
	}
	return r
}
```
