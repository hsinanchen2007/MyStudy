
```python []
"""
# Definition for a Node.
class Node:
    def __init__(self, val, prev, next, child):
        self.val = val
        self.prev = prev
        self.next = next
        self.child = child
"""
class Solution:
    def flatten(self, head: 'Node') -> 'Node':
        #此题的本质也就是深度优先遍历，可以用递归来做
        if not head:
            return None
       
        #定义深度遍历函数
        def dfs(head):
            if not head:
                return None
            p1=dfs(head.child)#p1指针指向子链表的末尾--即head.child为子链表的头部，p1为子链表的尾部
            p2=dfs(head.next)#p2指针指向next链表的末尾--即head.next为next链表的头部，p2为next链表的尾部
            if head.child and head.next:
                head.next.prev=p1
                p1.next=head.next
                head.next=head.child
                head.child.prev=head
                head.child=None
                return p2
            elif not head.child and head.next:
                return p2
            elif not head.next and head.child:
                head.next=head.child
                head.child.prev=head
                head.child=None
                return p1
            else:
                return head
        
        dfs(head)
        return head
            
            
            
```

