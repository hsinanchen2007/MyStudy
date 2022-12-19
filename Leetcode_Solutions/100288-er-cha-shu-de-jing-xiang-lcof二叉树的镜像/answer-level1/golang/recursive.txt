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
func mirrorTree(root *TreeNode) *TreeNode {
    if root == nil {
        return root
    }
    t := root.Left
    root.Left = root.Right
    root.Right = t
    mirrorTree(root.Left)
    mirrorTree(root.Right)
    return root

}
```