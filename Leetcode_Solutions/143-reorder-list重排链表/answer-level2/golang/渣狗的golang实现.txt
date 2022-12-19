```
 // 找到中心节点，将后半段反转，依次插入前半段
func reorderList(head *ListNode)  {
    if head == nil {
        return
    }
    slow,fast := head,head
    for fast != nil && fast.Next != nil {
        fast = fast.Next.Next
        slow = slow.Next
    }
    // 此时slow已经在中间位置, 1-2-3-4 在3的位置,1-2-3-4-5,在3的位置,只需要将3之后的节点反转,依次插入,后半段总比前半段短
    // 后半段
    right := slow.Next
    // 将前半段的尾节点指向空
    slow.Next = nil
    dummy := &ListNode{Next:head}
    // 反转right
    right = reverse(right)

    for right != nil {
        // 暂存下一个节点
        l := head.Next
        r := right.Next
        // 前半段节点指向后半段节点
        head.Next = right
        // 递推
        right = r
        // 新增节点指向旧的下一个节点
        head.Next.Next = l
        head = l
    }
    head = dummy.Next
}

func reverse(node *ListNode) *ListNode {
    var pre *ListNode
    for node != nil {
        next := node.Next
        node.Next = pre
        pre = node
        node = next
    }
    return pre
}
```