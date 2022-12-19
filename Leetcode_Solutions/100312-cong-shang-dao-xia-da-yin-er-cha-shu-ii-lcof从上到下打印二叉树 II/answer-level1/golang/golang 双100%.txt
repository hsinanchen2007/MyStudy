### 解题思路
bfs

### 代码

```golang
func levelOrder(root *TreeNode) [][]int {
    if root == nil {
        return [][]int{}
    }
    queue := []*TreeNode{root}
    res := make([][]int,0)
    ans := 0
    for len(queue)>0 {
        n := len(queue)
        res = append(res,make([]int,0))
        for i:=0;i<n;i++ {
            top := queue[0]
            queue = queue[1:]
            res[ans] = append(res[ans],top.Val)
            if top.Left != nil {
                queue = append(queue,top.Left)
            }
            if top.Right != nil {
                queue = append(queue,top.Right)
            }
        }
        ans++
    }
    return res
}
```