![image.png](https://pic.leetcode-cn.com/131d181c9057567bcaee46e2cc92cb169a4cbadee3d03b087bcac3e10b24495b-image.png)


```

'''
把每个区间的开始点和结束点抽象成两个事件
从左到右遍历每一个航班序号，如果当前航班序号有开始事件，预定数增加事件对应的预定数
如果当前航班前一个航班有结束事件，预定数减少前一个事件的预定数
一次扫描可以解决问题

'''

from typing import List
from collections import Counter
class Solution:
    def corpFlightBookings(self, bookings: List[List[int]], n: int) -> List[int]:
        enter, leave = Counter(), Counter()
        for start, end, order in bookings:
            enter[start] += order
            leave[end] += order

        ans = [0 for _ in range(n)]
        order = 0
        for i in range(1, n+1):
            if i in enter:
                order += enter[i]
            if i-1 in leave:
                order -= leave[i-1]

            ans[i-1] = order

        return ans
```
