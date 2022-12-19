![image.png](https://pic.leetcode-cn.com/04aecf41bfb5d70f75e5720bc566c9f02235f3424b887bf0f42091f9217e8fb6-image.png)


```
'''
枚举每一个数的4个因子即可
'''


from typing import List
from math import sqrt, floor
class Solution:
    def getFactor(self, num) -> List:
        factor = []
        for val in range(1, 1 + int(floor(sqrt(num)))):
            if num % val == 0:
                if num // val != val:
                    factor.extend([val, num // val])
                else:
                    factor.append(val)
                if len(factor) > 4:
                    break

        return factor if len(factor) == 4 else []

    def sumFourDivisors(self, nums: List[int]) -> int:
        ans = 0
        for val in nums:
            ans += sum(self.getFactor(val))
        return ans
```
