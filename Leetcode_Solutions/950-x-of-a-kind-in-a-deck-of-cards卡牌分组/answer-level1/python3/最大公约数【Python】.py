### 思路

**数学**

```
直接调用 Python 的 collections 库，Counter 统计。
然后计算所有整数出现次数的最大公约数。
```

##### Python3代码

```python
from typing import List
import collections
import math

class Solution:
    def hasGroupsSizeX(self, deck: List[int]) -> bool:
        # Counter统计出来是一个字典
        c = list(collections.Counter(deck).values())
        res = c[0]
        # 求所有数的最大公约数
        for x in c:
            res = math.gcd(res, x)
        return res > 1
```

### GitHub链接

[Python](https://github.com/Wonz5130/LeetCode-Solutions/blob/master/solutions/0914-X-of-a-Kind-in-a-Deck-of-Cards/0914.py)