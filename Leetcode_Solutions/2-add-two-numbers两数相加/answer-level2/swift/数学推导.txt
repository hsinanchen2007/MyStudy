```
var l1h = l1, l2h = l2, res: ListNode?, head: ListNode?, p = 0
        while l1h != nil && l2h != nil {
            let node = ListNode(((l1h?.val ?? 0) + (l2h?.val ?? 0) + p) % 10)
            p = ((l1h?.val ?? 0) + (l2h?.val ?? 0) + p) / 10
            if head == nil {
                head = node
            }
            res?.next = node
            res = node
            l1h = l1h?.next
            l2h = l2h?.next
        }
        while l1h != nil {
            let node = ListNode(((l1h?.val ?? 0) + p) % 10)
            p = ((l1h?.val ?? 0) + p) / 10
            res?.next = node
            res = node
            l1h = l1h?.next
        }
        while l2h != nil {
            let node = ListNode(((l2h?.val ?? 0) + p) % 10)
            p = ((l2h?.val ?? 0) + p) / 10
            res?.next = node
            res = node
            l2h = l2h?.next
        }
        if p > 0 {
            let node = ListNode(p)
            res?.next = node
        }
        return head
```
