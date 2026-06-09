### 解题思路
就很直接的思路

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def deleteNode(self, head: ListNode, val: int) -> ListNode:
        node = head
        if node.val == val:
            return node.next
        while node:
            if(node.next.val == val):
                node.next = node.next.next
                break
            node = node.next
        return head
```