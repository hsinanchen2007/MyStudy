![image.png](https://pic.leetcode-cn.com/dd3d626bd682c9fd2f28f33605501a453d14b16f199773a78d002986739b0957-image.png)


```

'''
两个坐标轴维度上的开销是互相不会影响的，
所有点的x, y两个坐标分别组成两个序列，两个序列中的最小开销分开算
其实问题转换成找一个数，让这个数到序列里面每一个值的距离和最小，
这个数其实就是序列的中位数，就这么简单
'''

from typing import List
class Solution:

    def getMinSum(self, data: List[int]):
        data.sort()

        mid_val = data[len(data)//2]
        sum = 0
        for val in data:
            sum += abs(val - mid_val)
        return sum

    def minTotalDistance(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        col_list = []
        row_list = []

        for i in range(m):
            for j in range(n):
                if grid[i][j]:
                    row_list.append(i)
                    col_list.append(j)

        return self.getMinSum(row_list) + self.getMinSum(col_list)
```
