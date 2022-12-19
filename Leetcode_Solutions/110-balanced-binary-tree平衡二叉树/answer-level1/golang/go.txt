递归
```
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func GetDepth(root *TreeNode) int {
	if root == nil {
		return 0
	}
	return max(GetDepth(root.Left),GetDepth(root.Right)) + 1
}

func isBalanced(root *TreeNode) bool {
    if root == nil {
		return true
	}
    return abs(GetDepth(root.Left),GetDepth(root.Right)) <= 1 && isBalanced(root.Left) && isBalanced(root.Right)
}

func max(a,b int) int{
    if a > b{
        return a
    }
    return b
}

func abs(a,b int) int{
    if a > b {
        return a-b
    }
    return b-a
}

```
