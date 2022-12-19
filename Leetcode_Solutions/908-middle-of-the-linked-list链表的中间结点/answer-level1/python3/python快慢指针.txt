
```
class Solution:
    def middleNode(self, head: ListNode) -> ListNode:
        slow=head
        fast=head
        while fast.next:
            fast=fast.next
            slow=slow.next
            if fast.next:
                fast=fast.next
        return slow
```
