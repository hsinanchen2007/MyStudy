### 解题思路
 - 1->2->3->Null; Null
 - 2->3->Null; 1->Null
 - 3->Null; 2->1->Null
 - Null; 3->2->1->Null

### 代码

```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        p = None
        while head:
            p, head.next, head = head, p, head.next
        return p
            
```