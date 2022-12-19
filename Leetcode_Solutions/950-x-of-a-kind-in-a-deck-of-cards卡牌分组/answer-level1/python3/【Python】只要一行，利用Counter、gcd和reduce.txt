解题思路上，只要想清楚就不难。key不重要，key的计数是否有大于1的公约数，决定了本题是否有解。

具体方案上，充分利用Python语言的优势，可以把问题简化为一行操作。

```python
from collections import Counter
from functools import reduce


class Solution:
    def hasGroupsSizeX(self, deck: List[int]) -> bool:
        return reduce(math.gcd, Counter(deck).values()) > 1
```

> 执行用时 : `40 ms`, 在所有 Python3 提交中击败了`97.91%`的用户
> 内存消耗 : `14 MB`, 在所有 Python3 提交中击败了`5.38%`的用户