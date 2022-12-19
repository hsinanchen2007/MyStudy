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
func levelOrder(root *TreeNode) [][]int {
    if root == nil{
        return nil
    }
    res := [][]int{}
    queue := []*TreeNode{}
    queue = append(queue,root)
    for len(queue)!=0{
        rs := []int{}
        times := len(queue)
        for i := 0;i<times;i++{
            node := queue[0]
            queue = queue[1:]
            rs = append(rs,node.Val)
            if node.Left != nil{
                queue =append(queue,node.Left)
            }
            if node.Right !=nil{
                queue = append(queue,node.Right)
            }
        }
        res = append(res,rs)
    }
    return res
}
```