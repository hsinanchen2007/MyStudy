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
func sufficientSubset(root *TreeNode, limit int) *TreeNode {
    var l, r *TreeNode 

    if root == nil {
        return nil
    }
    if root.Left == nil && root.Right == nil {
        if root.Val < limit {
            return nil
        } 
        return root
    } 

    l = sufficientSubset(root.Left, limit-root.Val)
    r = sufficientSubset(root.Right, limit-root.Val) 
    
    if l==nil && r ==nil {
        return nil
    }


    root.Left = l 
    root.Right = r 
    return root
}
```