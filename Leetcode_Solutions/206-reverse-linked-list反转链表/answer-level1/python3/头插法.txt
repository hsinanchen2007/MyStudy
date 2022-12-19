### 解题思路
从旧链表取的每一个结点，用头插法插入新链表，返回新链表
38ms

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None
class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        p,q,t = head,None,None
        while p:
            t = p
            p = p.next
            t.next = q
            q = t
        return q
```