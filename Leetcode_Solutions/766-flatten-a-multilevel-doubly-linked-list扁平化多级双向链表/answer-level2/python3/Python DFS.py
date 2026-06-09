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
        if head == None: return None
        def dfs(node):
            cur = node
            pre = Node(0)
            pre.next = cur
            while cur != None:
                if cur.child != None:
                    temp = cur.next
                    child, last = dfs(cur.child)
                    cur.child = None
                    cur.next = child
                    child.prev = cur
                    last.next = temp
                    if temp != None: temp.prev = last
                    cur = temp
                    pre = last
                else:
                    pre = pre.next
                    cur = cur.next
            return node, pre
        res, _ = dfs(head)
        return res

```