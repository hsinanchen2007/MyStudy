```python
class Solution:
    def removeElements(self, head: ListNode, val: int) -> ListNode:
        if head: head.next = self.removeElements(head.next, val)
        return head.next if head and head.val == val else head
```
- 递归：每次都返回从当前位置算起第一个有效的节点或None

```python
class Solution:
    def removeElements(self, head: ListNode, val: int) -> ListNode:
        while head and head.val == val:
            head = head.next
        pre, cur = head, head and head.next
        while cur:
            if cur.val == val:
                pre.next = cur = cur.next
            else:
                pre, cur = cur, cur.next
        return head
```
- 迭代：
- 第一个 while 用于找到应该返回的链表头（应该跳过所有特殊 val 的节点）
- 第二个 while 用于把前一个节点指针接到下一个节点（如果当前节点值为 val）