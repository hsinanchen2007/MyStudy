![image.png](https://pic.leetcode-cn.com/ac764d20a0cde0fd1ad79416373d07f5093b29671f517b8a4f23bef1ed563ba4-image.png)


```
'''
简单位运算判断是否合法即可
每一行最多坐两家人，状态很有限
'''

from typing import List
class Solution:
    def maxNumberOfFamilies(self, n: int, reservedSeats: List[List[int]]) -> int:
        vals = {}

        for row, seat in [(row-1, seat-1) for row, seat in reservedSeats]:
            if row not in vals:
                vals[row] = 0
            vals[row] |= (1 << seat)

        ans = 0
        for val in vals.values():
            if val & 0b111111110 == 0:
                ans += 2

            elif val & (0b1111 << 1) == 0 or val & (0b1111 << 3) == 0 or val & (0b1111 << 5) == 0:
                ans += 1

        ans += (n - len(vals)) * 2
        return ans
```
