若令等价的骨牌为同一类型的骨牌，
则先用字典记录各类型骨牌出现的频数。
然后对这些频数逐一计算组合数，
最后将这些组合数求和即可。

对于组合数C(m, n)，
若n = 2,
则C(m, n) = sum(range(m))。 

```
from typing import List

class Solution:
    def numEquivDominoPairs(self, dominoes: List[List[int]]) -> int:
        d = {}
        for dmn in dominoes:
            if (tuple(dmn), tuple(reversed(dmn))) in d:
                d[(tuple(dmn), tuple(reversed(dmn)))] += 1
            elif (tuple(reversed(dmn)), tuple(dmn)) in d:
                d[(tuple(reversed(dmn)), tuple(dmn))] += 1
            else:
                d[(tuple(dmn), tuple(reversed(dmn)))] = 1
        return sum([sum(range(v)) for v in d.values()])
```
时间复杂度：O(n)
