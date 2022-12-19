```python
class Solution:
    def copyRandomList(self, head: 'Node') -> 'Node':
        
        cur = head
        while cur:
            node = Node(cur.val)
            node.next = cur.next
            cur.next = node
            cur = node.next
        
        cur = head
        while cur:
            if cur.random: cur.next.random = cur.random.next
            cur = cur.next.next

        copy_head = cur = None
        if head:
            cur = head
            copy_head = cur1 = head.next
            cur.next = cur1.next
            cur = cur.next 
        while cur:
            cur1.next = cur.next
            cur1 = cur1.next
            cur.next = cur1.next 
            cur = cur.next 
        return copy_head 
```