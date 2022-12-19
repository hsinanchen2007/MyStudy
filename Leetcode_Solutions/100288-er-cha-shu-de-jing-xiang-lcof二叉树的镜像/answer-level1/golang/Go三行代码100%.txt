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
    if root==nil{
        return nil
    }
    return &TreeNode{root.Val,mirrorTree(root.Right),mirrorTree(root.Left)}
}
```