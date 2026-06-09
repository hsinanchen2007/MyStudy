
```
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func inorderTraversal(root *TreeNode) []int {
    s := make([]*TreeNode, 0)
    rs := make([]int, 0)
    
    if root == nil {
        return rs
    }
    
    c := root
    for c != nil || len(s) != 0 {
        if c != nil {
            s = append(s, c)
            c = c.Left
        } else {
            tmp := s[len(s)-1]
            rs = append(rs, tmp.Val)
            s = s[:len(s)-1]
            c = tmp.Right
        }
    }
    
    return rs
}
```