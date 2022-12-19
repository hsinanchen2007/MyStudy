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
    if A==nil||B==nil{
        return false
    }
    res:=false
    if A.Val==B.Val{
        res=equal(A,B)
    }
    if !res{
        res=isSubStructure(A.Left,B)
    }
    if !res{
        res=isSubStructure(A.Right,B)
    }
    return res
}

func equal(A,B *TreeNode)bool{
    if B==nil{
        return true
    }else if A==nil{
        return false
    }
    if A.Val!=B.Val{
        return false
    }
    return equal(A.Left,B.Left)&&equal(A.Right,B.Right)
}
```