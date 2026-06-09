### 解题思路
bfs遍历 
每一次取当前的作为cur 如果左儿子 和 右儿子 哪个不为空 就哪个输出

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
    queue := []*TreeNode{}
    queue = append(queue,root)
    ans := []int{}
    for len(queue)!=0{
        cur := queue[0]
        queue=queue[1:]
        if cur!=nil{
            ans = append(ans,cur.Val)
            if cur.Left!=nil{
                queue = append(queue,cur.Left)    
            }
            if cur.Right!=nil{
                queue = append(queue,cur.Right)    
            }
        }
        
    }
    return ans
}
```