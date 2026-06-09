

```golang
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func sumOfLeftLeaves(root *TreeNode) int {
	if root == nil {
		return 0
	}
	// 左子树为空，则只需遍历右子树
	if root.Left == nil {
		return sumOfLeftLeaves(root.Right)
	}
	// 左结点为叶子节点，则返回左结点+右子树
	if root.Left.Left == nil && root.Left.Right == nil {
		return root.Left.Val + sumOfLeftLeaves(root.Right)
	}
	// 其他情况
	return sumOfLeftLeaves(root.Left) + sumOfLeftLeaves(root.Right)
}

```