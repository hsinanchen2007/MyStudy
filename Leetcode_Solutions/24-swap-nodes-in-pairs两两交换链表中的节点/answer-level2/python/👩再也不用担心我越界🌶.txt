### 解题思路
模拟交换即可

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def swapPairs(self, head: ListNode) -> ListNode:
        h = ListNode(-1)
        h.next = head
        p = h
        while p:
            if p.next and p.next.next:
                t = p.next
                p.next = t.next
                t.next = p.next.next
                p.next.next = t
            try:
                p = p.next.next
            except:
                p = p.next
        return h.next
```