![image.png](https://pic.leetcode-cn.com/c539b528ae97390915fd7581b74583f4bee1872cf294f48e792d1b3c15fff1c7-image.png)


```
'''
二元一次方程求解
'''

from typing import List
class Solution:
    def numOfBurgers(self, tomatoSlices: int, cheeseSlices: int) -> List[int]:
        m, n = tomatoSlices, cheeseSlices
        if m - 2*n >= 0 and m % 2 == 0:
            x = (m - 2*n) // 2
            return [x, n-x] if n-x >= 0 else []
        return []
```
