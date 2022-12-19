
```golang
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

func convertBST(root *TreeNode) *TreeNode {
    sum := 0
    bst(root,&sum)
    return root
}
func bst(root *TreeNode,cnt *int) *TreeNode {
    if root != nil{
        bst(root.Right,cnt)
        *cnt += root.Val
        root.Val = *cnt
        bst(root.Left,cnt)
    }
    return root
}


```