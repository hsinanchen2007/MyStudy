

```golang
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func levelOrder(root *TreeNode) []int {
    if root == nil{
        return nil
    }
    queue := []*TreeNode{}
    res := []int{}
    queue = append(queue,root)
    for len(queue) != 0{
        node := queue[0]
        res = append(res,node.Val)
        if node.Left !=nil{
            queue = append(queue,node.Left)
        }
        if node.Right!=nil{
            queue = append(queue,node.Right)
        }
        if len(queue)==1{
            queue = []*TreeNode{}
        }else{
            queue = queue[1:]
        }
    }
    return res
}
```