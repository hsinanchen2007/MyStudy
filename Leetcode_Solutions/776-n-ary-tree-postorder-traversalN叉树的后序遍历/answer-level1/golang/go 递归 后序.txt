```

func postorder(root *Node) []int {
	var res = make([]int, 0)
	helper(root, &res)
	return res
}

func helper(root *Node, res *[]int) {
	if root == nil {
		return
	}
	for _, v := range root.Children {
		helper(v, res)
	}
	*res = append(*res, root.Val)
}
```
