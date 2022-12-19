```python
class Solution:
    def combine(self, n, k):
        cans = {i+1 for i in range(n)}
        
        def backtrack(temp, cans, k, res):
            if len(temp) == k:
                res.append(temp[:])
                return res
            if len(cans)+len(temp)<k:
                return res
            for x in cans:
                temp.append(x)
                cans_ = {y for y in cans if y>x}  # 滤重
                res = backtrack(temp, cans_, k, res)
                temp.pop()
            return res

        res = backtrack([], cans, k, [])
        return res
```