### 解题思路
此处撰写解题思路

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def hasCycle(self, head: ListNode) -> bool:
        if(head==None or head.next == None):return False
        slow = head
        quick = slow.next
        while(quick !=slow):
            if(quick ==None or quick.next == None): return False
            quick=quick.next.next
            slow = slow.next
        return True
```