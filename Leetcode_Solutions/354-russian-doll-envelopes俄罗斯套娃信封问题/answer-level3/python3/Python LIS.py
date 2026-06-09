![image.png](https://pic.leetcode-cn.com/46ce0998fecfd95e37eb964babc068a2a462c767c40f9480640c72592bc9c575-image.png)


```
'''
二维LIS算法找最长递增序列长度
将序列按照第一维升序，第二位降序排列，
然后对第二维数据进行LIS, 找最长递增子串长度
巧妙把同样宽度， 高度递增的不合法序列滤掉
'''

from typing import List
import bisect
class Solution:
    def maxEnvelopes(self, envelopes: List[List[int]]) -> int:
        l = envelopes
        l.sort(key = lambda x : (x[0], -x[1]))

        lis = []
        for pair in l:
            val = pair[1]

            if len(lis) == 0 or val > lis[-1]:
                lis.append(val)
            else:
                idx = bisect.bisect_right(lis, val)
                if idx >= 0 and idx < len(lis):
                    if idx == 0 or lis[idx-1] < val:
                        lis[idx] = val

        return len(lis)
```
