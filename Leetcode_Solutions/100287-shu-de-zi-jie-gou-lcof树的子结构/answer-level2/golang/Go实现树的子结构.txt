

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
    if B ==nil|| A==nil{
        return false
    }
    if process(A,B){
        return true
    }
    return isSubStructure(A.Left,B) ||isSubStructure(A.Right,B)
   
}

func process(A ,B *TreeNode)bool{
    if  B==nil{
        return true
    }
    if A == nil &&B!=nil{
        return false
    }
    if A.Val == B.Val{
        return process(A.Left,B.Left)&&process(A.Right,B.Right)
    }
    return false
}
```