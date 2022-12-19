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
func mergeTrees(t1 *TreeNode, t2 *TreeNode) *TreeNode {
    if t1 == nil && t2 == nil{
        return nil
    }
    if t1 == nil && t2 != nil{
        return t2
    }
    if t1 != nil && t2 == nil{
        return t1
    }
    t1.Val += t2.Val
    t1.Left = mergeTrees(t2.Left,t1.Left)
    t1.Right = mergeTrees(t2.Right,t1.Right)
    return t1
}
```