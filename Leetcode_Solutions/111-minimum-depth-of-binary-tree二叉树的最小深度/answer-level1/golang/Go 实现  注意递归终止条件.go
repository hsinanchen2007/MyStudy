```
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func minDepth(root *TreeNode) int {
    if root == nil{
        return 0
    }
    if root.Left ==nil&&root.Right== nil{
        return 1
    }
    if root.Left == nil&&root.Right!= nil{
        return minDepth(root.Right)+1
    }
    if root.Right ==nil &&root.Left!= nil{
        return minDepth(root.Left)+1
    }
    leftMin := minDepth(root.Left)
    rightMin := minDepth(root.Right)
    if leftMin<rightMin{
        return leftMin+1
    }else {
        return rightMin+1
    }
}
```
