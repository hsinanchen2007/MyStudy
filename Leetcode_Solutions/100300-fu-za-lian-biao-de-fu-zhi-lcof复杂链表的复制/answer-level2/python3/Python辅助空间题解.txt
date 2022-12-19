### 代码

```python3
"""
# Definition for a Node.
class Node:
    def __init__(self, x: int, next: 'Node' = None, random: 'Node' = None):
        self.val = int(x)
        self.next = next
        self.random = random
"""
class Solution:
    def copyRandomList(self, head: 'Node') -> 'Node': 
        if head is None:
            return None
        p1=head
        newHead=Node(0)
        p2=newHead
        note={}
        while p1 is not None:
            if p1!=head:
                p2.next=Node(0)
                p2=p2.next
            p2.val=p1.val
            note[p1]=p2
            p1=p1.next
        p1=head
        p2=newHead
        while p1 is not None:
            if p1!=head:
                p2=p2.next
            if p1.random is not None:
                p2.random=note[p1.random]
            p1=p1.next
        return newHead
```