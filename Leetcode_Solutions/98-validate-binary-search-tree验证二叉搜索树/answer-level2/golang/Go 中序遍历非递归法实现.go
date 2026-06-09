# **中序遍历稍微改动一下就可以了**
```
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func isValidBST(root *TreeNode) bool {
    if root == nil{
        return true
    }
    res,stack := []int{},[]*TreeNode{}
    for len(stack)!= 0 || root != nil{
        if root != nil{
            stack = append(stack,root)
            root =root.Left
        }else{
            node := stack[len(stack)-1]
            stack = stack[:len(stack)-1]
            root = node.Right
            res = append(res,node.Val)
            if len(res)>=2&&res[len(res)-1]<=res[len(res)-2]{
                return false
            }
        }
    }
    return true
}
```
