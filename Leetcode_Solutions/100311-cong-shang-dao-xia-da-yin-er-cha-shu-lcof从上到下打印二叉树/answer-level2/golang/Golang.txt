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
func levelOrder(root *TreeNode) []int {
    if root==nil{
        return []int{}
    }
    queue,res:=[]*TreeNode{},[]int{}
    queue=append(queue,root)
    for{
        if len(queue)==0{
            return res
        }
        res=append(res,queue[0].Val)
        if queue[0].Left!=nil{
            queue=append(queue,queue[0].Left)
        }
        if queue[0].Right!=nil{
            queue=append(queue,queue[0].Right)
        }
        queue=queue[1:len(queue)]
    }
}
```