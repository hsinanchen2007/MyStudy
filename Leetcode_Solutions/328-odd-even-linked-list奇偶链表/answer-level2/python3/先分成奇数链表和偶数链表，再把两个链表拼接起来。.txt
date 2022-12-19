```
class Solution:
    def oddEvenList(self, head: ListNode) -> ListNode:
        if not head or not head.next: return head

        odd, even = head, head.next

        tmpodd, tmpeven = odd, even
        while tmpeven and tmpeven.next:
            tmpodd.next = tmpeven.next
            tmpodd = tmpodd.next
            tmpeven.next = tmpodd.next
            tmpeven = tmpeven.next
        tmpodd.next = even
        return odd
```
