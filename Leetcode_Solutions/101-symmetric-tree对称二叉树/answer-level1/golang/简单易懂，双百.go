```
func isSymmetric(root *TreeNode) bool {
	return isTwoSymmetric(root, root)
}

func isTwoSymmetric(r1, r2 *TreeNode) bool {
	if r1 == nil {
		return r2 == nil
	}
	if r2 == nil {
		return r1 == nil
	}
	return r1.Val == r2.Val &&
		isTwoSymmetric(r1.Left, r2.Right) &&
		isTwoSymmetric(r2.Left, r1.Right)
}
```
