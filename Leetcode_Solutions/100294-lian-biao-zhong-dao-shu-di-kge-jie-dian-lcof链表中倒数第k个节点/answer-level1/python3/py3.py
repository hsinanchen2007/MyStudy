### 解题思路
先测链表长度，找出head应在的节点，直接把该节点设为head

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def getKthFromEnd(self, head: ListNode, k: int) -> ListNode:
        h = head
        l = 0
        while h is not None:
            l += 1
            h = h.next
        for i in range(l - k):
            head = head.next
        return head
```