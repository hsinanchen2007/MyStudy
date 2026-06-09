```
//迭代
func lowestCommonAncestor(root, p, q *TreeNode) *TreeNode {
	pVal, qVal := p.Val, q.Val
	node := root
	for node != nil {
		parentVal := node.Val
		switch {
		case pVal > parentVal && qVal > parentVal:
			node = node.Right
		case pVal < parentVal && qVal < parentVal:
			node = node.Left
		default:
			return node
		}
	}
	return nil
}

//递归
func lowestCommonAncestor(root, p, q *TreeNode) *TreeNode {
	pVal, qVal, rootVal := p.Val, q.Val, root.Val
	switch {
	case pVal > rootVal && qVal > rootVal:
		return lowestCommonAncestor(root.Right, p, q)
	case pVal < rootVal && qVal < rootVal:
		return lowestCommonAncestor(root.Left, p, q)
	default:
		return root
	}
}
```
