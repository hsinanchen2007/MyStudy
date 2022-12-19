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
    return todo(root)
}

func todo(root *TreeNode)*TreeNode{
    if root==nil{
        return nil
    }
    res:=&TreeNode{Val:root.Val,Left:nil,Right:nil}
    res.Right=todo(root.Left)
    res.Left=todo(root.Right)
    return res
}
```