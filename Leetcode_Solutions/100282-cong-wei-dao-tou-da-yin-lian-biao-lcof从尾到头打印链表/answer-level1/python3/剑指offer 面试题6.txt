### 解题思路
简单递归

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def reversePrint(self, head: ListNode) -> List[int]:
        if head:
            return self.reversePrint(head.next) + [head.val]
        else:
            return []
```