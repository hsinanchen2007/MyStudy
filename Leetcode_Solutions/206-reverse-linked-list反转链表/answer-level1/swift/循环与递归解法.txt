```循环 []
func reverseList(_ head: ListNode?) -> ListNode? {
        //*solution（循环迭代）
       var prev: ListNode? = nil
       var curr = head
       //循环链表并翻转
       while curr != nil {
           let next = curr?.next
           curr?.next = prev
           prev = curr!
           if next == nil {
               break
           }else {
               curr = next
           }
       }
       return curr
    }
```
```递归 []
func reverseList(_ head: ListNode?) -> ListNode? {
        //*solution (递归)
        // 空链表 || 抵达链表尾部
        if head == nil || head?.next == nil {
            return head
        }
        let node = reverseList(head?.next)
        // node1 (head) -> node2 (head.next)
        head?.next?.next = head
        head?.next = nil
        return node
    }
```
