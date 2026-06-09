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
func isSubStructure(A *TreeNode, B *TreeNode) bool {

    if A == nil || B == nil {
        return false
    }
    if A.Val == B.Val {
        return isSameStruct(A, B)
    }
    return isSubStructure(A.Left, B) || isSubStructure(A.Right, B)
}

func isSameStruct(A *TreeNode, B*TreeNode) bool {

    if B == nil {
        return true
    }
    if A == nil {
        return false
    }
    return A.Val == B.Val && isSameStruct(A.Left, B.Left) && isSameStruct(A.Right, B.Right)
}
```