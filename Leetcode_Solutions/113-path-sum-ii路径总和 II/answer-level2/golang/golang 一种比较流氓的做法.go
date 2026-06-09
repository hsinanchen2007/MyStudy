```
func pathSum(root *TreeNode, sum int) [][]int {
	if root == nil {
		return [][]int{}
	}

	if root.Left == nil && root.Right == nil {
		if root.Val == sum {
			return [][]int{{root.Val}}
		} else {
			return [][]int{}
		}
	}

	l := pathSum(root.Left, sum - root.Val)
	r := pathSum(root.Right, sum - root.Val)

	for i := 0; i < len(l); i++ {
		l[i] = append([]int{root.Val}, l[i]...)
	}

	for i := 0; i < len(r); i++ {
		r[i] = append([]int{root.Val}, r[i]...)
	}

	res := append(l, r...)
	return res
}
```
