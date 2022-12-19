### 解题思路
见注释

### 代码

```python3
from itertools import groupby
class Solution:
    def canPlaceFlowers(self, flowerbed: List[int], n: int) -> bool:
        nmax = 0
        zflowerbed = [0] + flowerbed + [0]      # 前后补0
        for i in range(1,len(zflowerbed)-1):    # 注意边界，补的0是虚的，不能种花
            if sum(zflowerbed[i-1:i+2]) == 0:   # 连续3个0
                zflowerbed[i] = 1               # 中间种花
                nmax += 1                       # 计数
        return nmax >= n                        # 判断能否种下n株
```