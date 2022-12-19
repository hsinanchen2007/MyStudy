

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
    if len(preorder) == 0 || len(inorder) == 0{
        return nil
    }
    var index int
    root := &TreeNode{Val:preorder[0]}
    for i := range inorder{
        if inorder[i] == preorder[0]{
            index = i
            break
        }
    }
    root.Left = buildTree(preorder[1:index+1],inorder[:index])
    root.Right = buildTree(preorder[index+1:],inorder[index+1:])
    return root
}
```