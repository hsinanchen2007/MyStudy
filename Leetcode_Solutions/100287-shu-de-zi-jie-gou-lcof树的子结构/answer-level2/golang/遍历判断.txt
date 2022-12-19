```
func isSubStructure(A *TreeNode, B *TreeNode) bool {
    if A == nil || B == nil {
        return false
    }
    return helper(A, B) || isSubStructure(A.Left, B) || isSubStructure(A.Right, B)
}

func helper(A *TreeNode, B *TreeNode) bool { 
    if B == nil {
        return true
    }
    if A == nil {
        return false
    }
    if A.Val != B.Val {
        return false
    }
    return helper(A.Left, B.Left) && helper(A.Right, B.Right)
}
```
