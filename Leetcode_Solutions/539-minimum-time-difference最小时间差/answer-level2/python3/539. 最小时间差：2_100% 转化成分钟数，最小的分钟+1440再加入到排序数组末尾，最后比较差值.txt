![image.png](https://pic.leetcode-cn.com/82ba5c35af4cfc78860e8f88eb21d3b9e1ef83a200c3fce10f8ffd754545742e-image.png)


```python []
class Solution:
    def findMinDifference(self, timePoints: List[str]) -> int:
        d = set()
        for c in timePoints:
            k = int(c[: 2]) * 60 + int(c[3: ])
            if k in d:  #可能快在了判重这里
                return 0
            d.add(k)
        d = sorted(d)
        d.append(d[0] + 1440)
        return min(d[i] - d[i - 1] for i in range(1, len(d)))
```
```python []
class Solution:
    def findMinDifference(self, timePoints: List[str]) -> int:
        d = [1440]
        for c in timePoints:
            k = int(c[: 2]) * 60 + int(c[3: ])
            i = bisect.bisect(d, k)
            d.insert(i, k)
            if d[i - 1] == d[i]:
                return 0
        d[-1] += d[0]
        return min(d[i] - d[i - 1] for i in range(1, len(d)))
```
```python []
class Solution:
    def findMinDifference(self, timePoints: List[str]) -> int:
        d = [1440]
        [bisect.insort(d, int(c[: 2]) * 60 + int(c[3: ])) for c in timePoints]
        d[-1] += d[0]
        return min(d[i] - d[i - 1] for i in range(1, len(d)))
```

