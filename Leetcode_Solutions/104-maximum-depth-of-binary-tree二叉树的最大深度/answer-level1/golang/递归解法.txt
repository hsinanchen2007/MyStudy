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
    
    if root == nil { // 如果是空树
        return 0
    }
    
    // 分别计算左右子树的深度
    leftDepth := maxDepth(root.Left) 
    rightDepth := maxDepth(root.Right)
    
    // 返回当前深度1 + 左右子树的最大深度
    if leftDepth > rightDepth {
        return 1 + leftDepth
    }
    return 1 + rightDepth
    
}
```
