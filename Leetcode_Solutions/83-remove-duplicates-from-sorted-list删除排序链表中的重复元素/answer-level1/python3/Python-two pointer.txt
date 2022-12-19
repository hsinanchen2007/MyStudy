```
class Solution:
    def deleteDuplicates(self, head: ListNode) -> ListNode:
        if not (head and head.next):
            return head
        i,j = head,head
        while j:
            if i.val!=j.val:
                i = i.next
                i.val = j.val
            j = j.next
        i.next = None
        return head
```
