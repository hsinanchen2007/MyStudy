### 解题思路

头节点不是固定的，最好用伪指针。

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def deleteNode(self, head: ListNode, val: int) -> ListNode:
        fake_head = ListNode(0)
        last = fake_head
        while head:
            if head.val == val:
                last.next = head.next
                break
            else:
                last.next = head
                last = last.next
            head = head.next
        return fake_head.next
```