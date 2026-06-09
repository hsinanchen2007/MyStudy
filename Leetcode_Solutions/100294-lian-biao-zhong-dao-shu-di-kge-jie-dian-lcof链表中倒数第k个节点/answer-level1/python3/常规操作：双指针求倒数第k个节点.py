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
    def getKthFromEnd(self, head: ListNode, k: int) -> ListNode:
        if not head:
            return None
        if k < 1:
            return None
        cur = fast = head
        while k > 0:
            fast = fast.next
            k -= 1
        while fast:  # fast来到空
            fast = fast.next
            cur = cur.next
        return cur
```