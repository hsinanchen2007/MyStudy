```
var sum int = 0
func bstToGstSum(root *TreeNode) {
	if root == nil {
		return
	}
	bstToGstSum(root.Right)
	sum += root.Val
	root.Val = sum
	bstToGstSum(root.Left)
}

func bstToGst(root *TreeNode) *TreeNode {
	if root == nil {
		return nil
	}

    sum = 0
	bstToGstSum(root)
	return  root
}
```
