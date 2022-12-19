### 解题思路

虚拟头结点dummy,迭代head，所以不需要额外的空间来记录当前的指针。
### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def deleteNode(self, head: ListNode, val: int) -> ListNode:
        dummy = ListNode(0)
        dummy.next = head
        if head.val == val:
            return head.next
        while head.next:
            if head.next.val == val:
                head.next = head.next.next
            else:
                head = head.next
        return dummy.next

```