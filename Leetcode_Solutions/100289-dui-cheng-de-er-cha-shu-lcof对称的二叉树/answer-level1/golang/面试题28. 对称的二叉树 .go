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
func isSymmetric(root *TreeNode) bool {

    if root == nil {
        return true
    }
    return isSame(root.Left, root.Right)
}

func isSame(A *TreeNode, B *TreeNode) bool {
    
    if A == nil && B == nil {
        return true
    }
    if A != nil && B == nil {
        return false
    }
    if A == nil && B != nil {
        return false
    }
    return A.Val == B.Val && isSame(A.Left, B.Right) && isSame(A.Right, B.Left)
}
```