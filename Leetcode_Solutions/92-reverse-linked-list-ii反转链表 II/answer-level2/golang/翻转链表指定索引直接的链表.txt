```
func reverseBetween(head *ListNode, m int, n int) *ListNode {
    if head == nil || m > n {
        return nil
    }
    
    //申请节点指向头节点
    fake := &ListNode{}
    fake.Next = head
    prve := fake
    
   //走到将要翻转节点的前一个节点 prev
    for i := 0; i < m-1; i++ {
        prve = prve.Next
    }

    //cur 第m个节点，也就是将要翻转的节点
    cur := prve.Next
    for i := m; i < n; i++ {
        tmp := cur.Next            //保存要反转节点的下一个节点
        cur.Next = tmp.Next    //当前节点指向 要放转节点的next节点，最终指向第m个节点的next
        tmp.Next = prve.Next  //第n个节点的next指向前一个节点
        prve.Next = tmp           // 第m个节点指向后面一个节点
    }
    
    return fake.Next    
}

```