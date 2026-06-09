### 解题思路
撸成list 后测len

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def middleNode(self, head: ListNode) -> ListNode:
        lst = []
        i = 0
        headtemp = head
        while head:
            lst.append(head.val)
            head = head.next

        for i in range(len(lst) // 2):
            headtemp = headtemp.next
        return headtemp



```