### 解题思路
提供一个思路：
统计各元素的数量，然后判断这些数量之间是否有大于1的最大公约数
强调：我觉得这段代码不能称之为算法，用了太多函数，但是学Python就是为了方便，偷个懒

### 代码

```python3
import collections
import math
from functools import reduce
class Solution:
    def hasGroupsSizeX(self, deck: List[int]) -> bool:
        #if len(deck)<2: return False
        return False if reduce(math.gcd,list(collections.Counter(deck).values()))<2 else True            
```