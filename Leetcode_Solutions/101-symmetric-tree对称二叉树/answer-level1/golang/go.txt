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
    if root == nil{
        return true
    }
    return mySym(root.Left,root.Right)
}

func mySym(r1 *TreeNode, r2 *TreeNode) bool{
    if r1 == nil && r2 == nil{
        return true
    }else if r1 == nil || r2 == nil{
        return false
    }else{
        return r1.Val == r2.Val && mySym(r1.Left,r2.Right) && mySym(r1.Right,r2.Left)
    }
}
```