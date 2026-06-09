### 解题思路
将值赋给空链表
将链表逆置

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

# class Solution:
#     def isPalindrome(self, head: ListNode) -> bool:
#         l = []
#         sub = head
#         while sub:
#             l.append(sub.val)
#             sub = sub.next
#         return l == l[::-1]

class Solution:
    def isPalindrome(self, head: ListNode) -> bool:
        l = []
        sub = head
        while sub:
            l.append(sub.val)
            sub = sub.next
        return l == l[::-1]
```