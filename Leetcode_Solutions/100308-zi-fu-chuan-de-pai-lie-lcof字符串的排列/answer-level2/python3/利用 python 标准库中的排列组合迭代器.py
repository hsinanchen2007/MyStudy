### 解题思路
利用 python 标准库中的排列组合迭代器。

### 代码

```python3
from typing import List
from itertools import permutations


class Solution:
    def permutation(self, s: str) -> List[str]:
        res = set()
        for i in permutations(s, len(s)):
            res.add(''.join(i))
        return list(res)
```