### 解题思路
如果用递归的话，思路很简单。
左右子树的指针交换，
然后递归对左右子树执行相同的操作。

### 代码

```golang
func invertTree(root *TreeNode) *TreeNode {
	if root == nil {
		return nil
	}

	root.Right, root.Left = invertTree(root.Left), 	invertTree(root.Right)
	return root
}

```