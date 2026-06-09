```
class Solution:
    def rotateRight(self, head: ListNode, k: int) -> ListNode:
        if head == None or head.next == None:
            return head

        pre = head
        count = 1
        while pre.next != None:
            count += 1
            pre = pre.next

        pre.next = head
        n = count - k%count
        q = pre

        for _ in range(n):
            q = q.next

        ret = q.next
        q.next = None
        return ret
```