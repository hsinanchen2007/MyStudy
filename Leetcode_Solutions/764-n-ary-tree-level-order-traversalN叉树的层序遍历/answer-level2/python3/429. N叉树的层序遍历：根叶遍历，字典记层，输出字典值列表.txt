扩数据之前最好是120ms,94%，现在大约1000ms这样。

```python []
class Solution:
    def levelOrder(self, root: 'Node') -> List[List[int]]:
        d = collections.defaultdict(list)
        def f(r, i = 0):
            if r:
                d[i] += [r.val]
                for j in r.children:
                    f(j, i + 1)
        f(root)
        return [*d.values()]
```
