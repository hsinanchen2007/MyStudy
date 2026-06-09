### 解题思路
用了两种方法，一种是把所有情况求出来，取一个。但显然太慢。

参考教程做了动态规划：
关键点在于如何保证下一个求的数一定是顺序递增的。

设置p2, p3, p5分别指向不同数，并乘2、3、5。取最小结果加在结果数组最后，相应p+1.

### 代码

```python3
from heapq import heappop, heappush
class Solution:
    def nthUglyNumber(self, n: int) -> int:
        p2, p3, p5 = 0, 0, 0
        rec = [1]
        for _ in range(n-1):
            ugly = min(rec[p2]*2, rec[p3]*3, rec[p5]*5)
            rec.append(ugly)
            if ugly == rec[p2]*2:
                p2 += 1
            if ugly == rec[p3]*3:
                p3 += 1
            if ugly == rec[p5]*5:
                p5 += 1
        return rec[-1]
```