### 解题思路
三指针法

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def swapPairs(self, head: ListNode) -> ListNode:
        if not head or not head.next:
            return head
        new_head = ListNode(-1)
        new_head.next = head
        p0 = new_head
        while p0.next and p0.next.next:
            p1 = p0.next
            p2 = p0.next.next
            p0.next = p2
            p1.next = p2.next
            p2.next = p1
            p0 = p0.next.next
        return  new_head.next
```