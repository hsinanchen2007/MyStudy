func removeNthFromEnd(head *ListNode, n int) *ListNode {
    if nil == head || nil == head.Next {
        return nil
    }
    // 给对应的节点建立hash字典
    m := make(map[int]*ListNode)
    i := 0
    // 设置一个前驱节点
    pre := &ListNode{
        Val: 0,
        Next: head,
    }
    cur := pre
    for nil != cur.Next {
        m[i] = cur.Next
        i++
        cur = cur.Next
    }
    if n > i {
        return nil
    }
    // 倒数第n个 即正数第i - n个
    p := m[i-n]
    // p的前驱节点
    pPre := m[i-n-1]
    if pPre == nil {
        pre.Next = p.Next
    } else {
        pPre.Next = p.Next
    }
    return pre.Next
}