
```python
"""
# Definition for a Node.
class Node:
    def __init__(self, val, prev, next, child):
        self.val = val
        self.prev = prev
        self.next = next
        self.child = child
"""
from itertools import chain

class Solution:
    def flatten(self, head: 'Node') -> 'Node':
        def gen(n): yield from chain([n], gen(n.child), gen(n.next)) if n else ()
        iters = gen(head); p = head and next(iters)
        for n in iters: p.next, n.prev, p.child, n.child, p = n, p, None, None, n
        return head
```
- 使用迭代器按顺序输出所有节点，然后连接

```python
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
        stack = [head] if head else []
        
        p = None
        while stack:
            node = stack.pop()
            if node.next:
                stack.append(node.next)
            if node.child:
                stack.append(node.child)
            if p:
                p.next = node
                node.prev = p
                p.child = node.child = None
            p = node
        
        return head
```
- 常规 DFS 遍历