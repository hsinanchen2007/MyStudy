## 递归处理

如果当前节点值为 0，且左右子树都被剪枝删除或为 nil 则减掉当前节点，即返回 nil
不满足上述条件的情况下直接返回即可

代码如下，0ms，2.3MB

```go
func pruneTree(root *TreeNode) *TreeNode {
    // 如果传入了空的树
	if root == nil {
		return nil
	}
    // 递归左右子树
	if root.Left != nil {
		root.Left = pruneTree(root.Left)
	}
	if root.Right != nil {
		root.Right = pruneTree(root.Right)
	}
    // 当前节点需要被删除
	if root.Left == nil && root.Right == nil && root.Val == 0 {
		return nil
	}
	return root
}
```