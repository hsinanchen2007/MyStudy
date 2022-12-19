## 思路：

迭代

```python
class Solution:
    def removeElements(self, head: ListNode, val: int) -> ListNode:
        dummy = ListNode(0)
        dummy.next = head
        prev = dummy
        last = prev.next
        while last :
            if last.val == val:
                prev.next = last.next
                last = prev.next
            else:
                prev = prev.next
                last = prev.next
        return dummy.next
```

递归

```python
class Solution:
    def removeElements(self, head: ListNode, val: int) -> ListNode:  
        if not head: return 
        head.next = self.removeElements(head.next, val)
        return head.next if head.val == val else head
```