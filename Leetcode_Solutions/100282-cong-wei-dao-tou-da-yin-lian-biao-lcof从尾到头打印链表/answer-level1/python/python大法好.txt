### 解题思路
就用一个列表存起来，然后反向输出

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def reversePrint(self, head: ListNode) -> List[int]:
        stack = [] 
        while head:
            stack.append(head.val)
            head=head.next
        return stack[::-1]
```