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
    def swapPairs(self, head: ListNode) -> ListNode:
        if not head:
            return head
        if not head.next:
            return head
        
        left = head
        begin = ListNode(0)
        begin.next = head
        pre = begin
        while left.next:
            right = left.next
            left.next = right.next
            right.next = left
            if pre:
                pre.next = right
            pre = left
            left = left.next
            if not left:
                break
        return begin.next
```