### 解题思路
排列，去重

### 代码

```python3
from itertools import permutations
from functools import reduce

class Solution:
    def numTilePossibilities(self, tiles: str) -> int:
        return len(set(reduce(operator.iconcat, [list(permutations(tiles, i)) for i in range(1,len(tiles) + 1)], [])))

```