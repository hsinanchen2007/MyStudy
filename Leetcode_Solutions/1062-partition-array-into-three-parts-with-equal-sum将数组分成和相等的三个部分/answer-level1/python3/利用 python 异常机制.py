### 解题思路

这道题有好多细节，我连错了四次……

解题思想和官方题解一样，不过使用了两个 python 工具，itertools.accumulate 和异常机制。

### 代码

```python3
from itertools import accumulate


class Solution:
    def canThreePartsEqualSum(self, A: List[int]) -> bool:
        SUM = list(accumulate(A))
        # print(SUM)
        if SUM[-1] % 3 != 0:
            return False
        else:
            fi = SUM[-1] // 3
            fj = 2 * SUM[-1] // 3
            try:
                i = SUM.index(fi)
                SUM.index(fj, i + 1, len(SUM) - 1)
            except ValueError:
                return False
            else:
                return True

```