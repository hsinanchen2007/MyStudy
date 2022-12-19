```python
class Solution:
    def countComponents(self, n: int, edges: List[List[int]]) -> int:
        # Union find
        dic = {}
        def find(x):
            dic.setdefault(x, x)
            if x != dic[x]:
                dic[x] = find(dic[x])
            return dic[x]
        def union(a, b):
            a_root = find(a)
            b_root = find(b)
            dic[b_root] = a_root
        for a, b in edges:
            union(a, b)

        res = set()
        for i in range(n):
            res.add(find(i))
        return len(res)
```