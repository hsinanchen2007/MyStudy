```
class Solution:
    def middleNode(self, head: ListNode) -> ListNode:
        slow=head
        fast=head
        while fast.next and fast.next.next:
            fast=fast.next.next
            slow=slow.next

        if fast.next and not fast.next.next:
            return slow.next
        else:
            return slow
```
```
class Solution:
    def middleNode(self, head: ListNode) -> ListNode:

        count=1
        fast=head
        while fast.next:
            count+=1
            fast=fast.next
       
        count=int(count/2)
        slow=head
        while count>0:
            slow=slow.next
            count-=1

        return slow
```