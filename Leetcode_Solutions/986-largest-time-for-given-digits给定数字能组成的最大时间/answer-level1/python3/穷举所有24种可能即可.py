四个数按照先后顺序排列，一共就有4×3×2×1=24种可能的全排列，计算各个组合对应的时刻，取满足条件的最大值即可。

```
from itertools import permutations
class Solution:
    def largestTimeFromDigits(self, A):
        """
        :param A: List[int]
        :return: str
        """
        max_time, res = 0, ''
        for ht,  hb, mt, mb in permutations(A):
            hour, minute = ht * 10 + hb, mt * 10 + mb
            t = hour * 60 + minute
            if hour < 24 and minute < 60 and t >= max_time:
                max_time, res = t, "{}{}:{}{}".format(ht, hb, mt, mb)
        return res
```