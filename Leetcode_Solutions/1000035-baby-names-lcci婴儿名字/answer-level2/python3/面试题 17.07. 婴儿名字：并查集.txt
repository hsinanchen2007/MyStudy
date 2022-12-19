
在中等题里算是比较长的且复杂的代码了。

```python []
class Solution:
    def trulyMostPopular(self, names: List[str], synonyms: List[str]) -> List[str]:
        p = {}
        for s in synonyms:
            a, b = s[1: -1].split(',')
            p[a], p[b] = p.get(a, [a]), p.get(b, [b])
            if p[a] is not p[b]:
                p[a].extend(p[b])
                for c in p[b]:
                    p[c] = p[a]
        d = {}
        for name in p:
            if id(p[name]) not in d:
                d[id(p[name])] = min(p[name])
        q = collections.defaultdict(int)
        for s in names:
            i = s.find('(')
            name, count = s[: i], int(s[i + 1: -1])
            q[name in p and d[id(p[name])] or name] += count
        return [f'{name}({count})' for name, count in q.items()]
```