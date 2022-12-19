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
    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        res = head
        fast, slow = head, head
        for _ in range(n):
            fast = fast.next
        if not fast:
            return res.next
        while fast.next:
            fast = fast.next
            slow = slow.next
        slow.next = slow.next.next
        return res

```