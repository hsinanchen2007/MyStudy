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
    def kthToLast(self, head: ListNode, k: int) -> int:
        cur = head
        n = 0
        while cur.next:
            n += 1
            cur = cur.next
        c,cur2 = 0,head
        while c <= n-k:
            c += 1
            cur2 = cur2.next
        return cur2.val
```