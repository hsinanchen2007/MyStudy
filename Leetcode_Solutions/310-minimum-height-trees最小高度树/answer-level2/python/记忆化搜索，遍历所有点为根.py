# 思路
第一次做的时候，直接遍历所有点为根，超时了。然后观察了一下发现有许多重复计算，于是改成了记忆化搜索。
时间没有优势，空间没有优势，唯一的优势就是写的短。

# 代码
```python
import collections

class Solution:
    def findMinHeightTrees(self, n: int, edges: List[List[int]]) -> List[int]:
        if n == 0: return []
        g = collections.defaultdict(set)
        for i, j in edges: g[i].add(j), g[j].add(i)
        t = dict()
        def func(s, k): # 以s为父结点时，k的高度
            if (s, k) not in t:
                c = [func(k, e) for e in g[k] if s != e]
                t[s, k] = max(c) + 1 if c else 1
            return t[s, k]
        a = [func(None, i) for i in range(n)]
        m = min(a)
        a = [i for i, c in enumerate(a) if c == m]
        return a
```
