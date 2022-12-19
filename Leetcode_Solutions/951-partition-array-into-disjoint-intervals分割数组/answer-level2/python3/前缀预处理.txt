### 解题思路
预处理记录左侧前缀最大值数组和右侧前缀最小值数组，然后遍历寻找第一个可行解。

### 代码

```python3
class Solution:
    def partitionDisjoint(self, A: List[int]) -> int:
        n = len(A)
        lmax = []
        for i in A:
            if len(lmax) == 0:
                lmax.append(i)
            else:
                lmax.append(max(i, lmax[-1]))
        rmin = []
        for i in range(n):
            if len(rmin) == 0:
                rmin.append(A[n - i - 1])
            else:
                rmin.append(min(A[n - i - 1], rmin[-1]))
        for i in range(n):
            if lmax[i] <= rmin[n - i - 2]:
                return i + 1
        return 0
        
```