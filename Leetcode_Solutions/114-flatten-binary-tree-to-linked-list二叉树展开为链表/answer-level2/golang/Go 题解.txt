思路：题目要求原地展开，故不能使用数组类变量存储全部节点值再重构树。将左右子树分别递归展开，将原左子树变为节点的右子树，再将原右子树变为当前右子树最右节点的右子树。

```
执行用时 :0 ms, 在所有 Go 提交中击败了100.00%的用户
内存消耗 :6.8 MB, 在所有 Go 提交中击败了46.43%的用户
```
```Go []
func flatten(root *TreeNode) {
	if root == nil {
		return
	}
	flatten(root.Left)
	flatten(root.Right)
	r := root.Right
	root.Right, root.Left = root.Left, nil
	for root.Right != nil {
		root = root.Right
	}
	root.Right = r
}
```