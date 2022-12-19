
不断地将下一个节点放入链表最前端：时间 O(N) 空间 O(1)

```python
class Solution(object):
    def reverseList(self, head):
        if not head:
            return head
        p1, p2 = None, None
        while head:
            p1 = head.next
            head.next = p2
            p2 = head
            head = p1
        return p2
```

更直观的方法：

用栈的性质，将节点压入栈中，再将节点pop出来，构成一个新的链表：时间 O(N) 空间 O(N)

```python
class Solution(object):
    def reverseList(self, head):
        if not head:
            return head
        h = ListNode(None)
        h.next = head
        cur = h
        lst = []
        while cur.next:
            cur = cur.next
            lst.append(cur)
        cur = h
        while lst:
            cur.next = lst.pop()
            cur = cur.next
            cur.next = None
        return h.next
```

