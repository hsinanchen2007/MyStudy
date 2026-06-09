1. 将每个颜色的index放在一起， 排序
2. 计算最近的距离， 就二分查找的插入点p， 以及p-1中的最小值。
3. 处理一下查找各种情况：比如列表为空， 插入点在第一个或者最后一个。

```python3
from bisect import bisect 
class Solution:
    def shortestDistanceColor(self, colors: List[int], queries: List[List[int]]) -> List[int]:
        d = collections.defaultdict(list)
        for i,x in enumerate(colors):
            d[x].append(i)
        for i in [1,2,3]: d[i] = sorted(d[i])
        
        def find(i,c):
            p = bisect(d[c],i)
            l = [abs(d[c][x]-i) for x in [p,p-1] if 0<=x<len(d[c])]
            return min(l) if l else -1
        
        return [find(i,c) for i,c in queries]
```
复杂度：
1. space O(N)
2. time (NlogN)