### 解题思路
#Counter直接用values就可以將值取出..這是一個thm..
#第二個是連續求gcd 可以使用reduce


### 代码

```python3
from collections import Counter
from math import gcd
from functools import reduce
class Solution:
    def hasGroupsSizeX(self, l: List[int]) -> bool:
        c = Counter(l).values()
        return reduce(gcd,c)>=2

```