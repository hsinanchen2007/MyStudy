### 解题思路
双指针，值对调

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def partition(self, head: ListNode, x: int) -> ListNode:
        i, j = head, head
        while j:
            if j.val < x:
                i.val, j.val = j.val, i.val
                i = i.next
            j = j.next
        return head



```