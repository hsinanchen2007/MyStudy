### 解题思路
直接采用python3自带的reverse方法进行翻转

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def reversePrint(self, head: ListNode) -> List[int]:
        l = []
        while head is not None:
            l.append(head.val)
            head = head.next
        l.reverse()
        return l
```