### 解题思路

采用递归的方法,遍历节点，然后交换左右子树

### 代码

```golang
func invertTree(root *TreeNode) *TreeNode {
	if root == nil {
		return nil
	}
	var right *TreeNode = invertTree(root.Right)
	var left *TreeNode = invertTree(root.Left)
	root.Left = right
	root.Right = left
	return root
}
```