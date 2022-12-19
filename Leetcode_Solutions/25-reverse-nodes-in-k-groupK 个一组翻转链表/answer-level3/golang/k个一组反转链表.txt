该题主要在于**处理好关键点的连接**：**正在反转的子链的首尾节点**、**已反转的上一条子链的尾节点的记录**
处理好这两个点就可以了，详细看代码吧

```go
func reverseKGroup(head *ListNode, k int) *ListNode {
    if head == nil || head.Next == nil {
        return head
    } else if k == 1 {
        return head
    }
    p := head
    length := 0
    for p != nil {
        length++
        p = p.Next
    }
    if length < k {
        return head
    }
    var pre, cur *ListNode
    var newHead, subHead, subTail, leftTail *ListNode
    cur = head
    for m := 1; m <= length / k; m++ {
        for i := 1; i <= k; i++ {
            if i % k == 1 {
                subTail = cur
                next := cur.Next
                cur.Next = pre
                pre, cur = cur, next
            } else if i % k == 0 {
                if newHead == nil {
                    newHead = cur
                }
                subHead = cur
                if leftTail != nil {
                    leftTail.Next = subHead
                }
                leftTail = subTail
                subTail.Next = cur.Next
                next := cur.Next
                cur.Next = pre
                pre, cur = nil, next
            } else {
                next := cur.Next
                cur.Next = pre
                pre, cur = cur, next
            }
        }
    }
    return newHead
}
```
