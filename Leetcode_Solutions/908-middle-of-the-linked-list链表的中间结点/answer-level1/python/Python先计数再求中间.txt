
### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def middleNode(self, head: ListNode) -> ListNode:
        num = 0
        if head == None:
            return
        node = head
        while node != None:
            num += 1
            node = node.next
        count = num//2
        while count != 0:
            head = head.next
            count -= 1
        return head
```