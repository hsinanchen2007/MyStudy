### 解题思路
fractions: https://blog.csdn.net/baiyibin0530/article/details/77197302

gcd: https://blog.csdn.net/weixin_43731785/article/details/84350761?depth_1-utm_source=distribute.pc_relevant.none-task&utm_source=distribute.pc_relevant.none-task

numerator denominator: 分子 分母
### 代码

```python3
class Solution:
    def hasGroupsSizeX(self, deck: List[int]) -> bool:
        # if len(deck) < 2: return False
        
        from fractions import gcd
        from collections import Counter
        count = Counter(deck).values()
        return reduce(gcd, count) >= 2
```