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
    if root==nil{
        return true
    }
    return f(root.Left,root.Right)
}

func f(l,r *TreeNode)bool{
    if l==nil&&r==nil{
        return true
    }else if l==nil||r==nil{
        return false
    }else if l.Val!=r.Val{
        return false
    }
    return f(l.Left,r.Right)&&f(l.Right,r.Left)
}
```