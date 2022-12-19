Go，0ms(100%)，2.4MB(73%)
**大致思路**：
1. 找到第一个大于x的节点的前驱`lastLessNode`，该前驱用于拼接后续从链表中抽离出来的小于x的节点组成的子链
2. 使用双指针`pre`和`cur`，`cur`用于与x比较，`pre`用于拼接抽离`cur`节点的后面的子链
3. 将所有符合`cur.Val < x`的节点抽离出来组成一条子链
4. `cur`遍历链表完成后，拼接子链，需要注意空指针问题，无论是`lastLessNode`还是值小于x的子链

```
func partition(head *ListNode, x int) *ListNode {
    if head == nil || head.Next == nil {
        return head
    }
    var lastLessNode, pre, cur *ListNode
    cur = head
    // 找到第一个大于x的节点的前驱作为lastLessNode的值
    for cur != nil && cur.Val < x {
        lastLessNode, cur = cur, cur.Next
    }
    pre = lastLessNode
    // 将值小于x的节点抽离出来，放到一个新的链表中
    var lessHead, lessTail *ListNode
    for cur != nil {
        if cur.Val < x {
            if lessHead == nil {
                lessHead = cur
                lessTail = cur
            } else {
                lessTail.Next = cur
                lessTail = cur
            }
            cur = cur.Next
            pre.Next = cur
        } else {
            pre, cur = cur, cur.Next
        }
    }
    // 拼接新链表到lastLessNode后面，需要注意空指针问题
    if lessHead != nil {
        if lastLessNode == nil {
            lessTail.Next = head
            head = lessHead
        } else {
            lessTail.Next = lastLessNode.Next
            lastLessNode.Next = lessHead
        }
    }
    

    return head
}
```
