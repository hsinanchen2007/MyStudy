python3 
时间上优于68%的python解答 空间上优于90%的python解答


```
class Solution:
    def removeElements(self, head: ListNode, val: int) -> ListNode:
        if head == None:
            return None
        dummy_head = ListNode(0)
        dummy_head.next = head
        cur = dummy_head
        while cur:
            if cur.next == None and cur.val == val:
                cur = None
            elif cur.next != None and cur.next.val == val:
                cur.next = cur.next.next
            else:
                cur = cur.next
        return dummy_head.next
```

