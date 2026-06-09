通过计算并比较从根结点到目标值节点的路径上各个节点的最近叶节点

```
func findClosestLeaf(root *TreeNode, k int) int {
    var ans int
    deep := 1001
    
    var pre []*TreeNode
    var findK func(*TreeNode, int)
    findK = func(root *TreeNode, k int) {
        var pLast *TreeNode
        nd:=root
        for nd != nil {
            pre = append(pre, nd)
            nd = nd.Left
        }
        
        for len(pre) > 0 {
            nd = pre[len(pre)-1]
            if nd.Right == nil || nd.Right == pLast {
                if nd.Val == k {
                    return
                }
                pLast = nd
                pre = pre[:len(pre)-1]
                
            } else {
                nd = nd.Right
                for nd != nil {
                    pre = append(pre, nd)
                    nd = nd.Left
                }
                
            }
        }       
    }
    // find k node and its ancestor
    findK(root, k)
    
    var findTarget func(*TreeNode, int)
    findTarget = func(nd *TreeNode, level int) {
        if nd == nil {
            return
        }
        if nd.Left == nil && nd.Right == nil && level < deep {
            ans = nd.Val
            deep = level
        }
        findTarget(nd.Left, level+1)
        findTarget(nd.Right, level+1)
    }
    
    for i:=len(pre)-1; i>=0; i-- {
        findTarget(pre[i], len(pre)-1-i)
    }
    
    return ans
}

