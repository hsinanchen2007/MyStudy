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
    @staticmethod
    def reversePrint(head):
        stack = []
        result = []
        while head != None:
            stack.append(head.val)
            head = head.next
        while stack != []:
            result.append(stack.pop())
        return result
```