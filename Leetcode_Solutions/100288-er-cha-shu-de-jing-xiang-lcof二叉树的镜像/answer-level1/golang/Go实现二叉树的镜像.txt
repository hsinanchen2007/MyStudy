

```golang
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func mirrorTree(root *TreeNode) *TreeNode {
    if root == nil{
        return nil
    }
    root.Left = mirrorTree(root.Left)
    root.Right = mirrorTree(root.Right)
    root.Left,root.Right = root.Right,root.Left
    return root
}
```