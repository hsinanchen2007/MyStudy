

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def middleNode(self, head: ListNode) -> ListNode:
        newHead = head
        num = 0
        while newHead.next:
            newHead = newHead.next
            num += 1
        num = (num+1)//2
        nnum = 0
        while head.next:
            head = head.next
            nnum += 1
            if nnum == num:
                break
        return head
```