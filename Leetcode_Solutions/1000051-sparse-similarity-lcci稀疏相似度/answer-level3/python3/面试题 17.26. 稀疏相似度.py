### 解题思路

集合取并，round函数会被卡精度。

### 代码

```python []
class Solution:
    def computeSimilarities(self, docs: List[List[int]]) -> List[str]:
        ans, n, docs = [], len(docs), [*map(set, docs)]
        for i, j in itertools.combinations(range(n), 2):
            r = (p := len(docs[i] & docs[j])) / (len(docs[i]) + len(docs[j]) - p)
            r and ans.append(f'{i},{j}: {r + 1e-9:.4f}')
        return ans
```
```python []
class Solution:
    def computeSimilarities(self, docs: List[List[int]]) -> List[str]:
        ans = []
        d = collections.defaultdict(list)
        for i, arr in enumerate(docs):
            for j in arr:
                d[j].append(i)
        c = collections.Counter((i, j) for arr in d.values() for i, j in itertools.combinations(arr, 2))
        for (i, j), t in c.items():
            r = t / (len(docs[i]) + len(docs[j]) - t)
            r and ans.append(f'{i},{j}: {r + 1e-9:.4f}')
        return ans
```
