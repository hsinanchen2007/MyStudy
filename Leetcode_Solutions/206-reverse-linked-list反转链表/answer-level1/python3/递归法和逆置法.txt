### 解题思路
head.next表示head的下一位，此时head是4，则head.next是5，那么head.next.next表示5的下一位。
那么head.next.next = head，表示5的下一位是4.

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        if head == None or head.next == None:
            return head
        s = self.reverseList(head.next)
        head.next.next = head
        head.next = None
        return s

```