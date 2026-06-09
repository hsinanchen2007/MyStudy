```
class Solution:
    def getKthFromEnd(self, head: ListNode, k: int) -> ListNode:
        slow= quick = head 
        if k ==0: return None
        while k and quick:
            quick = quick.next
            k-=1
        if k != 0: return None
        while quick:
            quick =  quick.next 
            slow = slow.next 
        return slow
```
