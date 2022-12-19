运用广度优先的思想，本题非常容易想出题解。加上数据结构是树，可以不用考虑visited。

```go
func levelOrder(root *TreeNode) [][]int {
    var res [][]int
    if root == nil{
        return res
    }       
    var trees []*TreeNode
    trees = append(trees,root)    
    for len(trees) > 0 {
        var tmp []*TreeNode
        var o1 []int
        for _,v := range trees{
            o1=append(o1,v.Val)
            if v.Left != nil{
                tmp = append(tmp,v.Left)
            }
            if v.Right != nil{
                tmp = append(tmp,v.Right)
            }
        }
        res = append(res,o1)
        trees = tmp
    }
    return res
}
```
