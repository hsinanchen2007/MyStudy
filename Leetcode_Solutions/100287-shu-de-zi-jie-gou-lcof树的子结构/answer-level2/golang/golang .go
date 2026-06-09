```
func isSubStructure(A *TreeNode, B *TreeNode) bool {
    if B == nil {
        return false
    }
    if isSame(A, B) {
        return true
    }
    if A != nil {
        return isSubStructure(A.Left, B) || isSubStructure(A.Right, B)
    }
    return false
}

func isSame(A, B *TreeNode) bool {
    if B == nil {
        return true
    }
    if A == nil && B != nil {
        return false
    }
    if A.Val == B.Val {
        return isSame(A.Left, B.Left) && isSame(A.Right, B.Right) 
    }
    return false
}
```
