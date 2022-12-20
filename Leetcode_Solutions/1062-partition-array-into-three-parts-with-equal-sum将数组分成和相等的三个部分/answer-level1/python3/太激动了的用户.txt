### 解题思路
从头开始算和，和等于1/3sum的时候在原地开始算和....暴力

### 代码

```python
class Solution(object):
    def canThreePartsEqualSum(self, A):
        """
        :type A: List[int]
        :rtype: bool
        """
        n = len(A)
        an = sum(A)
        if an % 3 != 0:
            return False
        part1 = 0
        for i in range(n):
            part1 += A[i]
            if part1 == an // 3:
                j = i
                part2 = 0
                while j < n-1:
                    j += 1
                    part2 += A[j]
                    if part2 == an // 3:
                        part3 = 0
                        for t in range(j+1, n):
                            part3 += A[t]
                        if part2 == part3:
                            return True
        return False
```
