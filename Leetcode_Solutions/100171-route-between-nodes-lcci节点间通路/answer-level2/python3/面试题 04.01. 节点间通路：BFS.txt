### BFS

把图存成邻接表，用集合作为层次拓展的容器。

```python []
class Solution:
    def findWhetherExistsPath(self, n: int, graph: List[List[int]], start: int, target: int) -> bool:
        d = collections.defaultdict(list)
        for i, j in graph:
            d[i].append(j)
        q = {start}
        while q:
            if target in q:
                return True
            q = {j for i in q for j in d[i]}
```
```python []
class Solution:
    def findWhetherExistsPath(self, n: int, graph: List[List[int]], start: int, target: int) -> bool:
        d = collections.defaultdict(list)
        for i, j in graph:
            d[i].append(j)
        q = {start}
        while q:
            if target in q:
                return True
            q = {*itertools.chain(*map(d.__getitem__, q))}
```

### 双向BFS

不过似乎并没有更快，大概是大用例里的单链路太多了。

```python []
class Solution:
    def findWhetherExistsPath(self, n: int, graph: List[List[int]], start: int, target: int) -> bool:
        a = collections.defaultdict(list)
        b = collections.defaultdict(list)
        for i, j in graph:
            a[i].append(j)
            b[j].append(i)
        p, q = {start}, {target}
        while p and q:
            if target in p or start in q:
                return True
            p = {j for i in p for j in a[i]}
            q = {j for i in q for j in b[i]}
```
