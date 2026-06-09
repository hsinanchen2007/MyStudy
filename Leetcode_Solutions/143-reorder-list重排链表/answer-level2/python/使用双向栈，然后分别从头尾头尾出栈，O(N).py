

### 代码

```python
class Solution(object):
    def reorderList(self, head):
        """
        :type head: ListNode
        :rtype: None Do not return anything, modify head in-place instead.
        """

        if not head: return

        stack = []
        s = head
        while s.next:
            stack.append(s.next)
            s = s.next

        s = head
        n = 0
        while stack:
            if n % 2 == 0:
                one = stack.pop()
            else:
                one = stack.pop(0)
            one.next = None
            s.next = one
            s = s.next
            n += 1
```