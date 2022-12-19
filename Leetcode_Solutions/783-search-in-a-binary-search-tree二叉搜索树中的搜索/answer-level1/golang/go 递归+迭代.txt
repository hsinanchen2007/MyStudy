```
func searchBST(root *TreeNode, val int) *TreeNode {
	if root == nil {
		return nil
	}
	if root.Val == val {
		return root
	}
	if val < root.Val {
		return searchBST(root.Left, val)
	} else {
		return searchBST(root.Right, val)
	}
    return root
}
```

```
func searchBST(root *TreeNode, val int) *TreeNode {
	if root == nil {
		return nil
	}
	for root != nil && val != root.Val {
		if val < root.Val {
			return searchBST(root.Left, val)
		} else {
			return searchBST(root.Right, val)
		}
	}
	return root
}
```

