### 解题思路

递归，若当前节点的左子节点的左右子节点都为空，则当前节点的左子节点为左叶子结点，加上他的值，接着遍历当前节点的右子树。否则，遍历当前节点的左右子树。

### 代码

```golang
func sumOfLeftLeaves(root *TreeNode) int {
	if root == nil {
		return 0
	}
	if root.Left != nil && root.Left.Left == nil && root.Left.Right == nil {
		return root.Left.Val + sumOfLeftLeaves(root.Right)
	}
	return sumOfLeftLeaves(root.Left) + sumOfLeftLeaves(root.Right)
}
```