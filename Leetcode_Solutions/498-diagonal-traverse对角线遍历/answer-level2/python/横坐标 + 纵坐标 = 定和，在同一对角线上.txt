先根据横坐标与纵坐标之和是一个定值，在一条对角线上。
然后遍历这些数组，数组的反向，正向，反向...输出这些数字。

```python []
class Solution:
    def findDiagonalOrder(self, matrix: List[List[int]]) -> List[int]:
        group = collections.defaultdict(list)
        for r,row in enumerate(matrix):
            for c,num in enumerate(row):
                sums = r + c
                group[sums].append(num)
        res = []
        for k,s in enumerate(group.values()):
            if k % 2 == 0:
                s = s[::-1]
            for p in s:
                res.append(p)
        return res
```


