**关键**：该题的关键在于处理关键节点的连接，关键节点主要为：第m个节点及其前驱，第n各节点及其后继。实际上m和n将链表分为左中右三段，我们只需要处理好左子链表的尾节点、中间链表的首尾节点及右子链表的头结点即可。
```go
func reverseBetween(head *ListNode, m int, n int) *ListNode {
    if m == n {
        return head
    }
    var leftTail, midHead, midTail, rightHead *ListNode
    var pre, cur *ListNode
    cur = head
    // 标记关键点
    for i := 1; i <= n; i++ {
        if i < m {
            pre, cur = cur, cur.Next
        } else {
            // 关键点1
            if i == m {
                leftTail = pre
                midTail = cur
            }
            // 关键点2
            if i == n {
                midHead = cur
                rightHead = cur.Next
            }
            next := cur.Next
            cur.Next = pre
            pre, cur = cur, next
        }
    }
    // 拼接子链表
    if leftTail == nil {
        head = midHead
    } else {
        leftTail.Next = midHead
    }
    midTail.Next = rightHead
    
    return head
}
```