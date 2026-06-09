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
func rightSideView(root *TreeNode) []int {
    if root == nil{
        return []int{}
    }

    res := []int{}
    ch := make(chan *TreeNode, 1000)
    ch <- root
    for len(ch)>0 {
        
        level := len(ch)
        for i := 0; i< level; i++ {
            cur := <- ch
            // bfs 只保留每个level 第一个值
            if i == 0{
                res = append(res, cur.Val)
            }
            // 从右开始入队
            if cur.Right != nil {
                ch <- cur.Right
            }
            if cur.Left != nil{
                ch <- cur.Left
            }
        }
    }

    return res

}


```