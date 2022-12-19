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
func maxDepth(root *TreeNode) int {
    if root == nil {
        return 0
    }
    lm := maxDepth(root.Left)
    rm := maxDepth(root.Right)
    return max(lm,rm) +1
}
func max (a,b int)int{
    if a >b{
        return a
    }
    return b
}
```