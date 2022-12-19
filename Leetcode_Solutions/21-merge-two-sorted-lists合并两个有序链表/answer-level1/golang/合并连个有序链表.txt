func mergeTwoLists(l1 *ListNode, l2 *ListNode) *ListNode {
    headNode := ListNode{} //初始化头节点，默认Val为0
    var q *ListNode        
    q = &headNode          //指向头节点的指针，使用尾插法，q指向新链表的尾部
    for l1!=nil && l2!=nil{
        if l1.Val < l2.Val{
            q.Next = l1
            l1 = l1.Next
        }else{
            q.Next = l2
            l2 = l2.Next
        }
        q = q.Next
    }
    if l1 != nil{
        q.Next = l1
    }else if l2 != nil{
        q.Next = l2
    }

    return headNode.Next
}