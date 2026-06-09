```
func addOneRow(root *TreeNode, v int, d int) *TreeNode {
	if d == 1 {
		n := &TreeNode{Val: v}
		n.Left = root
		return n
	}
	dfsAddOneRow(root, v, 1, d)
	return root
}

func dfsAddOneRow(node *TreeNode, val, depth, n int) {
	if node == nil {
		return
	}
	if depth == n-1 {
		t := node.Left
		node.Left = &TreeNode{Val: val}
		node.Left.Left = t
		t = node.Right
		node.Right = &TreeNode{Val: val}
		node.Right.Right = t
	} else {
		dfsAddOneRow(node.Left, val, depth+1, n)
		dfsAddOneRow(node.Right, val, depth+1, n)
	}
}
```
