```
class Solution:
    def deleteDuplicates(self, head: ListNode) -> ListNode:
        if head is None:
            return head
        pre = head
        cur = pre.next
        while cur is not None:
            if cur.val == pre.val:
                cur = cur.next
                pre.next = cur
            else:
                pre = cur
                cur = cur.next
        return head 
        
```
