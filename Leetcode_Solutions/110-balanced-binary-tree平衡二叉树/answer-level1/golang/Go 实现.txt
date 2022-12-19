```
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
type Data struct{
    isB bool
    h float64
}

func isBalanced(root *TreeNode) bool {
    if root == nil{
        return true
    }
    return isBalance(root).isB
    
}

func isBalance(head *TreeNode)Data{
    if head == nil{
        return Data{true,0}
    }
    left := isBalance(head.Left)
    if !left.isB{
        return Data{false,0}
    }
    right := isBalance(head.Right)
    if !right.isB{
        return Data{false,0}
    }
    if math.Abs(float64(left.h-right.h))>1{
        return Data{false,0}
    }
    return Data{true,math.Max(float64(left.h),float64(right.h))+1}
}
```
