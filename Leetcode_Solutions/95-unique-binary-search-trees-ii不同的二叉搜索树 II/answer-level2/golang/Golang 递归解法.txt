
递归函数 generateTreesRecur(start, end int) 代表构造从 start 到 end 的这么多元素能形成的二叉搜索树

```
func generateTrees(n int) []*TreeNode {
    res := make([]*TreeNode, 0) 
    
    if n == 0 {
        return res
    }
    
    res = generateTreesRecur(1, n)
    return res
}

func generateTreesRecur(start, end int) []*TreeNode {
    res := make([]*TreeNode, 0)
    
    if start > end {
        root := &TreeNode {
            Val: 0,
            Left:  nil,
            Right: nil,
        }  
        res = append(res, root)
        return res
    }
    
    if start == end {
        root := &TreeNode {
            Val: start,
            Left:  nil,
            Right: nil,
        }
        res = append(res, root)
        return res
    }
    
    
   
    for i := start; i <= end; i++ {
        lt := generateTreesRecur(start, i-1)
        rt := generateTreesRecur(i+1, end) 
        for _, l := range lt {
            for _, r := range rt {
                root := &TreeNode{
                    Val: i,
                }
                if l.Val == 0 {
                    root.Left = nil
                } else {
                    root.Left = l
                }
                if r.Val == 0 {
                    root.Right = nil
                } else {
                    root.Right = r
                }
                
                res = append(res, root)
            }
        }
    }
    
    return res
}
```