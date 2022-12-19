没啥挑战，基本递归题

```
class Solution:
    def swapPairs(self, head: ListNode) -> ListNode:
        if not head:
            return
        if head and not head.next:
            return head
        temp=head.next
        head.next=self.swapPairs(head.next.next)
        temp.next=head
        return temp
```
