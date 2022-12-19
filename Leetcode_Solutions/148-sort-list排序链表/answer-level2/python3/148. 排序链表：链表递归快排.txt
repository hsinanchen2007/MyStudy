### 链表快排

递归函数栈似乎不太符合空间要求，不过比归并递归要快不少。

```python []
class Solution:
    def sortList(self, head: ListNode) -> ListNode:
        if not head or not head.next:
            return head
        val = head.val
        left, right, middle = l, r, m = ListNode(0), ListNode(0), ListNode(0)
        while head:
            if head.val < val:
                l.next = head
                l = l.next
            elif head.val > val:
                r.next = head
                r = r.next
            else:
                m.next = head
                m = m.next
            head = head.next
        l.next, r.next = None, None
        left.next, right.next = self.sortList(left.next), self.sortList(right.next)
        l = left
        while l.next:
            l = l.next
        l.next = middle.next
        m.next = right.next
        return left.next
```

### 数组法

空间完全不符合要求，但是最快。

```python []
class Solution:
    def sortList(self, head: ListNode) -> ListNode:
        ans, vals = ListNode(0), []
        ans.next = head
        while head:
            vals.append(head.val)
            head = head.next
        vals.sort()
        head = ans.next
        for val in vals:
            head.val, head = val, head.next
        return ans.next
```