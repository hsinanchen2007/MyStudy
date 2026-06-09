![临时.PNG](https://pic.leetcode-cn.com/f48f5bd28f5a2a86e2eb37a6e01ad9e2b087c42bdd5cd2babdf9ab881780c78a-%E4%B8%B4%E6%97%B6.PNG)

```
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def getDecimalValue(self, head: ListNode) -> int:
        ls = []
        while head:
            ls.append(str(head.val))
            head = head.next
        return int("".join(ls), 2)
```
