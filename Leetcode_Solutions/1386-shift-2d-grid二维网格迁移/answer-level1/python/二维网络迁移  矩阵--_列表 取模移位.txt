### 解题思路
矩阵转换为一维列表，然后就是对列表进行循环移位的过程。列表长度为L，最终移位的值取决于k = k % L
然后经过三次翻转便可以得到移位后的列表，再将列表转换为矩阵

### 代码

```python
#import numpy
class Solution(object):
    def shiftGrid(self, grid, k):
        R = len(grid)
        C = len(grid[0])
        k = k % (R*C)
        if k == 0:
            return grid
        ans = []
        for r in grid:
            ans += r
        ans = ans[::-1] #第一次翻转
        ans = list(reversed(ans[:k])) + ans[:k-1:-1] #前k个元素反转，后面元素再翻转 共三次
        #a = numpy.array(ans).reshape(C,R)  将列表变成矩阵
        m = 0
        for i in range(R):
            for j in range(C):
                grid[i][j] = ans[m]
                m += 1
        return  grid
```