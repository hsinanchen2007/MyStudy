![image.png](https://pic.leetcode-cn.com/853bed50d8d272f8830abab98841a462fc2521c1d653b0871df837b732138bac-image.png)


```

'''
二分搜索最大的D，让每个加油站之间的距离都小于等于D且总共新加的加油站个数小于等于K
'''

import math
from typing import List

class Solution:
    # 验证需要保证所有加油站距离都小于等于D的情况下，K个新加的加油站是否够用
    def isValid(self, D, dis, K):
        cnt = 0
        for d in dis:
            val = (d / D)
            floor_val = math.floor(val)
            if floor_val == val:
                cnt += int(floor_val) - 1
            else:
                cnt += int(floor_val)

            if cnt > K:
                return False
        return True

    def minmaxGasDist(self, stations: List[int], K: int) -> float:
        dis = []
        max_dis = -1
        for i in range(1, len(stations)):
            d = stations[i] - stations[i-1]
            dis.append(stations[i] - stations[i-1])
            max_dis = max(max_dis, d)

        l, r = 0, max_dis
        ans = -1.0
        while r - l >= 10 ** (-6):
            mid = l + (r - l) / 2
            if self.isValid(mid, dis, K):
                ans = mid
                r = mid
            else:
                l = mid
        return ans
```
