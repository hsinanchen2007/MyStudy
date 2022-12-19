```
func reverseList(head *ListNode) *ListNode {
    //申请临时节点
    var prv *ListNode = nil
    //保存头结点
    cur := head
    for cur != nil {
        tmp := cur.Next  //保存当前节点的下一个，用于迭代
        cur.Next = prv    //当前节点指向申请的临时节点
        prv = cur            // 临时节点向后移动一个节点，翻转成功一个节点
        cur = tmp           //当前节点指向下一个节点
    }
    return prv   //最后移动到链表尾部 ，也就是新的链表头部
}

```