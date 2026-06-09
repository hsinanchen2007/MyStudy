```
func listOfDepth(tree *TreeNode) []*ListNode {
    if tree == nil {
        return nil
    }
    var res []*ListNode
    q := []*TreeNode{tree}
    for len(q) > 0 {
        qlen := len(q)
        dummy := new(ListNode)
        cur := dummy
        for i := 0; i < qlen; i++ {
            node := &ListNode{
                q[i].Val, nil,
            }
            cur, cur.Next = node, node
            if q[i].Left != nil {
                q = append(q, q[i].Left)
            }
            if q[i].Right != nil {
                q = append(q, q[i].Right)
            }
        }
        q = q[qlen:]
        res = append(res, dummy.Next)
    }
    return res
}
```
