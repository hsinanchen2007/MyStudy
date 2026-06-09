### 解题思路
Counter用来统计频率
reduce用来迭代计算出最大公约数

### 代码

```python3
from collections import Counter
class Solution:
    def hasGroupsSizeX(self, deck: List[int]) -> bool:
        cnt=Counter(deck)   
        def gcd(x,y):
            return x if x==y else gcd(min(x,y),abs(x-y))
        ans=reduce(gcd,cnt.values())
        return True if ans>1 else False
```