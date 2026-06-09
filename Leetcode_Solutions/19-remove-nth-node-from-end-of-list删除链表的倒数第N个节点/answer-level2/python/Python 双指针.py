```python
class Solution:
    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        # 引入哑节点作为头结点避免特殊情况->删除头结点
        dummy = ListNode(0)
        dummy.next = head
        left = dummy
        right = dummy
        for i in range(n+1):
            right = right.next
        while right:
            right = right.next
            left = left.next
        left.next = left.next.next
        return dummy.next
```