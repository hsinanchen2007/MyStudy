### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def hasGroupsSizeX(self, deck: List[int]) -> bool:
        import math
        import collections
        vals=collections.Counter(deck).values()
        return reduce(math.gcd,vals)>=2
            
        
```