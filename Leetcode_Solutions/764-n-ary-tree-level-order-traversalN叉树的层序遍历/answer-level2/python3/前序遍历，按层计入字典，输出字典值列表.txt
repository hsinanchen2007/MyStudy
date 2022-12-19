最好一次是120ms,94.42%

```
class Solution:
    def levelOrder(self, root: 'Node') -> List[List[int]]:
        if not root:return []
        d=collections.defaultdict(list)
        def f(r,i=0):
            d[i]+=[r.val]
            for j in r.children:
                f(j,i+1)
        f(root)
        return list(d.values())
```
