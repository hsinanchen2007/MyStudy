广度优先搜索记录每一层最右侧节点的值，送入最终结果

```
func rightSideView(root *TreeNode) []int {
    var (
        cq, nq []*TreeNode
        res []int
        last int
    )
    
    cq = make([]*TreeNode, 0)
    res = make([]int, 0)
    
    if root == nil {
        return res
    }
    
    cq = append(cq, root)
    last = root.Val
    res = append(res, last)
    
    for len(cq) != 0 {        
        nq = make([]*TreeNode, 0) 
        for _, q := range cq {
            if q.Left != nil {
                nq = append(nq, q.Left)
                last = q.Left.Val
            } 
            if q.Right != nil {
                nq = append(nq, q.Right)
                last = q.Right.Val
            }
        }
        cq = nq
        if len(nq) != 0 {
            res = append(res, last) 
        }
    }
    return res
}
```

空间复杂度 O(n)
时间复杂度 O(n)