### 解题思路
用一个栈储存每一级具有child属性的节点的next节点，然后dfs就行了。
一定要记住最后要删除节点的child属性（不要问我怎么知道的，改了半天硬是不知道哪错了，想了好久才搞定）

### 代码

```python3
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
        if not head:
            return head
        stack = [head]
        prehead = Node(0,None,None,None)
        while stack:
            cur = stack.pop()
            if cur != head:
                prehead.next = cur
                cur.prev = prehead
            while cur.next != None or cur.child:
                if cur.child:
                    if cur.next:
                        stack.append(cur.next)
                    cur.next = cur.child
                    cur.child.prev = cur
                    cur.child = None
                    cur = cur.next
                else:
                    cur = cur.next
            prehead = cur

        return head
```