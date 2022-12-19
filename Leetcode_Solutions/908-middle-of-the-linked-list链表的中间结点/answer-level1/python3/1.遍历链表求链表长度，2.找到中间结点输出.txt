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
    def middleNode(self, head: ListNode) -> ListNode:
        length = 1
        p = head
        while p.next != None:
            p = p.next
            length += 1
        
        half = length//2
        p = head

        for _ in range(0, half, 1):
            p = p.next
        
        return p
```