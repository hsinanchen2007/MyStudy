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
        p = head
        mid = head
        while p.next and p.next.next:
            p = p.next.next
            mid = mid.next
        mid = mid.next if p.next else mid
        return mid
```