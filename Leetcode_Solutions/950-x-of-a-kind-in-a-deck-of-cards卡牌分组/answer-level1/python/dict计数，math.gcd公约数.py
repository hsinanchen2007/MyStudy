### 代码
```python
class Solution:
    def hasGroupsSizeX(self, deck: List[int]) -> bool:
        dic = collections.defaultdict(int)
        for num in deck:dic[num]+=1
        import math,functools
        res = functools.reduce(math.gcd, dic.values())
        return res >= 2     
```