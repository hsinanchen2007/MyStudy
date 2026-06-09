
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
    if root== nil{
        return true
    }
    return dfs(root.Left,root.Right)

}
func dfs(left,right *TreeNode) bool{
    if left ==nil && right!=nil||left!=nil&&right==nil{
        return false
    } 
    if left==nil&& right==nil{
        return true
    }
    if left.Val == right.Val{
        return dfs(left.Right,right.Left)&&dfs(left.Left,right.Right)
    }else{
        return false
    }
}
```