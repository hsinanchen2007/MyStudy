### 解题思路
纯数学
这个倒腾水壶的问题，就是判断最大公约数的问题

### 代码

```python3
import math
class Solution:
    def canMeasureWater(self, x: int, y: int, z: int) -> bool:
        if z>x+y:return False
        t=math.gcd(x,y)
        if t==0:
            return True if z==x or z==y else False
        else:
            return True if z%t==0 else False
```