

```golang
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func constructFromPrePost(pre []int, post []int) *TreeNode {
    if len(pre) == 0 || len(post)==0{
        return nil
    }
    root := &TreeNode{Val:pre[0]}
    if len(pre) == 1{
        return root
    }
    var index int
    for i  := range post{
        if post[i] == pre[1]{
            index = i
            break
        }
    }
    root.Left = constructFromPrePost(pre[1:index+2],post[:index+1])
    root.Right = constructFromPrePost(pre[index+2:],post[index+1:len(post)-1])
    return root
}
```