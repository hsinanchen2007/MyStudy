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
func buildTree(preorder []int, inorder []int) *TreeNode {
    if len(inorder)==0{
        return nil
    }
    var a int
    for i,v:= range inorder{
        if v==preorder[0]{
            a=i
            break
        }
    }
    return &TreeNode{preorder[0],buildTree(preorder[1:a+1],inorder[0:a]),buildTree(preorder[a+1:len(preorder)],inorder[a+1:len(inorder)])}
}
```