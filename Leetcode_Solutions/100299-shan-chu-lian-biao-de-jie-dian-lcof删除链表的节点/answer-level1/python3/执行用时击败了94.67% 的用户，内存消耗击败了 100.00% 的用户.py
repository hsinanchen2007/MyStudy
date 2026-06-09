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
    def deleteNode(self, head: ListNode, val: int) -> ListNode:
        prehead = ListNode(-1)
        res = prehead
        prehead.next = head
        while prehead.next:
            if prehead.next.val == val:
                prehead.next = prehead.next.next
                break
            else:
                prehead = prehead.next
        return res.next
                
```