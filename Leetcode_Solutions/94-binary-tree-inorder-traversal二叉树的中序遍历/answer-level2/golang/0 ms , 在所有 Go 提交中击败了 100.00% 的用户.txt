### 解题思路
此处撰写解题思路

### 代码

```golang
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
 // 中序遍历顺序，左-->根-->右
func inorderTraversal(root *TreeNode) []int {
	arr := make([]int, 0)
	return helper(root, &arr)
}

func helper(root *TreeNode, arr *[]int) []int {
	if root == nil {
		return nil
	}
	helper(root.Left, arr)
	*arr = append(*arr, root.Val)
	helper(root.Right, arr)
	return *arr
}
```