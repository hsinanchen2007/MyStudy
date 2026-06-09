```python
class Solution:
    def minSwapsCouples(self, row: List[int]) -> int:
        dic = {}
        def find(x):
            dic.setdefault(x, x)
            if x != dic[x]:
                dic[x] = find(dic[x])
            return dic[x]

        def union(a, b):
            dic[find(a)] = find(b)

        for i in range(0, len(row) * 2 - 1, 2): union(i, i + 1)
        res = collections.defaultdict(int)
        values = []
        for i in range(0, len(row) - 1, 2):
            a, b = row[i], row[i + 1]
            if a > b : a, b = b, a
            if  b - a == 1 and a % 2 == 0: continue
            union(a, b)
            values.append(a)
            values.append(b)
        for value in values:
            res[find(value)] += 1
    
        return sum(val // 2 - 1 for val in res.values())


```