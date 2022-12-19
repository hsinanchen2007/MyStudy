```
var currentMaxNode int

func isValidBinarySearchTree(root *TreeNode) bool {
	if root == nil {
		return true
	}
	if isValidBinarySearchTree(root.Right) {
		if currentMaxNode > root.Val {
			currentMaxNode = root.Val
			return isValidBinarySearchTree(root.Left)
		}
	}
	return false
}

func isValidBST(root *TreeNode) bool {
	if root == nil {
		return true
	}
	currentMaxNode = int(^uint(0) >> 1)
	return isValidBinarySearchTree(root)
}
```
