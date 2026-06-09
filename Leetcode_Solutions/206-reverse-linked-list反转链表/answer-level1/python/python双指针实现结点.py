### 解题思路
由于python可以同时赋值，故无需申请临时指针来完成结点交换，只需一个前向指针和当前指针即可完成链表反转

### 代码

```python
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def reverseList(self, head):
        cur, prev = head, None
        while cur:
            cur.next, prev, cur = prev, cur, cur.next
        return prev
```