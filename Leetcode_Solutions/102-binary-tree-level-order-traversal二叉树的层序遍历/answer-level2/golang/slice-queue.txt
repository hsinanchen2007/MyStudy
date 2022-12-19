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
    if root == nil {
        return nil
    }
    lvl := 0
    ans := [][]int{}
    queue := []*TreeNode{root}
    for len(queue) > 0 {
        ans = append(ans,[]int{})
        qlen := len(queue)
        for i := 0;i <qlen;i++{
            node := queue[0]
            queue = queue[1:len(queue)]
            li := ans[lvl]
            ans[lvl] = append(li,node.Val)

            if node.Left != nil{
                queue = append(queue,node.Left)
            }
            if node.Right != nil{
                queue = append(queue,node.Right)
            }
        }
        lvl++
    }
    return ans

   

}


```