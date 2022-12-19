## 思路
+ 首先如果点数小于 3 个，直接返回点数（因为肯定能组成直线）。
+ 我们对所有点遍历，记录包含这个点在内的所有直线中，能组成的点数最多的直线的点数数量。
+ 返回这些数量的最大值。
+ 怎么遍历呢？
+ 我们对一个点遍历的时候，再遍历所有点
    + 维护两个变量
    + 一个来记录和这个点相同的点（**重复点**）
    + 一个来记录**非重复点**和这个点组成的各个直线以及它们拥有的点数
    + 即使用哈希表，键为斜率，值是这个直线拥有的点数。这里使用 `Counter` 直接统计各个直线拥有的点数。
    + 返回最多拥有点数的直线所拥有的点数与重复点之和。
+ 可以参考分步代码
+ **重复点的处理**是难点。

## 分步代码

```python
from collections import Counter
class Solution:
    def maxPoints(self, points: List[List[int]]) -> int:
        
        def K(i,j):
            return float('Inf') if i[1] - j[1] == 0 else (i[0] - j[0]) / (i[1] - j[1]) 

        if len(points) <= 2:
            return len(points)
        
        maxans = 0
        for i in points:
            same = sum(1 for j in points if j == i)
            hashmap = Counter([K(i,j) for j in points if j != i])
            tempmax = hashmap.most_common(1)[0][1] if hashmap else 0
            maxans = max(same + tempmax, maxans)
        
        return maxans
```

## 一行代码

+ 其实就是分步代码利用生成器构造一下

```python
from collections import Counter
class Solution:
    def maxPoints(self, points: List[List[int]]) -> int:
        return max(sum(1 for j in points if j == i) + Counter([float('Inf') if i[1] - j[1] == 0 else (i[0] - j[0]) / (i[1] - j[1]) for j in points if j != i]).most_common(1)[0][1] if sum(1 for j in points if j == i) != len(points) else sum(1 for j in points if j == i) for i in points) if len(points) > 2 else len(points)
```
+ 枯燥的春节，只能写些朴实无华的一行流代码。