### 解题思路
check

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        if not head or not head.next: return head
        dummy = ListNode(0)
        p = head
        while p:
            tmp = dummy.next
            dummy.next = p
            p = p.next
            dummy.next.next = tmp
        return dummy.next

```