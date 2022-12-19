### 解题思路
- 首先判断边界条件，head==None或者head.next==None，直接返回head
- 循环反转单链表
- 

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        if head is None or head.next is None:
            return head
        pre = None
        cur = head
        h = head
        while cur:
            h = cur
            tmp = cur.next
            cur.next = pre
            pre = cur
            cur = tmp
        return h
```