### 解题思路
方法一：递归

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
        return nil
    }
    
    root.Left,root.Right = root.Right,root.Left
    invertTree(root.Left)
    invertTree(root.Right)
    return root
}
```