```
class Solution:
    def getDecimalValue(self, head: ListNode) -> int:
        ans = 0
        while head:
            ans = ans<<1
            ans = ans | head.val
            head = head.next
        return ans
```
