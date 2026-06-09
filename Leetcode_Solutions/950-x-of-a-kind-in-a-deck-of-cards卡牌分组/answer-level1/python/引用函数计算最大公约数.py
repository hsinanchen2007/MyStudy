### 解题思路
引用reduce和gcd，计算由频数组成的列表的最大公约数，最大公约数大于等于2则True，否则False

### 代码

```python3
class Solution:
    def hasGroupsSizeX(self, deck: List[int]) -> bool:
        from math import gcd
        from functools import reduce
        tem = {}
        tem1 = []
        for i in deck:
            if(tem.get(i) is None):
                tem[i] = 1
            else:
                tem[i]+=1
        for key in tem:
            tem1.append(tem[key])
        return reduce(gcd,tem1)>=2
        
        
            
            
```