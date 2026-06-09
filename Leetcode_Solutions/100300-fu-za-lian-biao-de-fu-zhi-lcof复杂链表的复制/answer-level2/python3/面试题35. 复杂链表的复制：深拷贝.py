
```python []
class Solution:
    def copyRandomList(self, head: 'Node') -> 'Node':
        d = {}
        def f(r):
            if r:
                if r not in d:
                    d[r] = Node(r.val, None, None)
                    d[r].next = f(r.next)
                    d[r].random = f(r.random)
                return d[r]
        return f(head)
```

```python []
class Solution:
    def copyRandomList(self, head: 'Node') -> 'Node':
        return copy.deepcopy(head)
```
