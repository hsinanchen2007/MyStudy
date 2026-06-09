## 思路:

我们只需固定一点，找这一点和其他点的距离，用哈希统计不同距离的个数，那么在其中一个距离下个数$A_k^2$，`k`为这个距离下的个数。

## 代码:

```python
class Solution:
    def numberOfBoomerangs(self, points: List[List[int]]) -> int:
        from collections import defaultdict
        n = len(points)
        res = 0
        
        def cal(i, j):
            return (points[i][0] - points[j][0]) ** 2 + (points[i][1] - points[j][1]) ** 2 
            
        res = 0
        for i in range(n):
            # 统计在i点下与其他点的距离
            lookup = defaultdict(int)
            for j in range(n):
                if i != j:
                    lookup[cal(i, j)] += 1
            # 排列组合
            for v in lookup.values():
                res += v * (v - 1)
        return res
        
```

