### 解题思路
把每层节点由左往右丢入队列
处理一层同时放入一层
直到队列为空
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
    queue := []*TreeNode{}
    if root == nil{
        return nil
    }
    rs:=[][]int{}
    queue = append(queue,root)
    for len(queue)>0{
        tempRs := []int{}
        times := len(queue)
        for i:= 0 ; i< times;i++{
            node := queue[0]
            queue = queue[1:]
            tempRs = append(tempRs,node.Val)
            if node.Left != nil{
                queue = append(queue,node.Left)
            }
            if node.Right != nil{
                queue = append(queue,node.Right)
            }
        }
        rs = append(rs,tempRs)
    }
    return rs
}
```