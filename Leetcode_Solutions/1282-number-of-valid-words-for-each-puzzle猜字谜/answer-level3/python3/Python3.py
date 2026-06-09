没注意谜面长度只有7，当时没做出来
```python
class Solution:
    def findNumOfValidWords(self, words: List[str], puzzles: List[str]) -> List[int]:
        w = [frozenset(i) for i in words if len(set(i)) <= 7]
        d = {}
        res = []
        for i in w:
            d[i] = d.get(i, 0) + 1
        for p in puzzles:
            ct = 0
            pr = (p[0],)
            p = set(p[1:])
            for i in range(len(p)+1):
                for c in itertools.combinations(p, i):
                    ct += d.get(frozenset(c+pr), 0)
            res.append(ct)
        return res
```
