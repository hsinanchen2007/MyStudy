```python
from copy import copy 
class Solution:
    def reverseList(self, head: ListNode) -> ListNode: 
        cur, pre = None, head
        while pre:
            t = copy(pre) 
            pre.next = cur
            cur, pre = pre, t.next
        return cur 
```
