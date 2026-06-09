### 解题思路
递归依次交换左子树与右子树的位置

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
func invertTree(root *TreeNode) *TreeNode {
    if root == nil {
        return root
    }
    if root.Left != nil || root.Right != nil {
        root.Left, root.Right = root.Right, root.Left
    } else {
        return root
    }

    invertTree(root.Left)
    invertTree(root.Right)

    return root
}
```