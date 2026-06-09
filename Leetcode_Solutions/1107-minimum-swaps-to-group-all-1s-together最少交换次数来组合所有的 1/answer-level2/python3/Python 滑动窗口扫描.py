![image.png](https://pic.leetcode-cn.com/17f0de310f8299475269568b11a938766e14db3006dc92c29446dbef422ba040-image.png)


```
'''
最终状态一定是n个1连在一起，那么只要能找到一个长度为n的窗口，
包含最多的1， 那么交换次数自然就是最少的
'''

from typing import List
from collections import Counter
class Solution:
    def minSwaps(self, data: List[int]) -> int:
        one_cnt = Counter(data)
        if one_cnt[1] <= 1:
            return 0
        window_len = one_cnt[1]
        one_cnt = Counter(data[:window_len])[1]

        l, r = 0, window_len - 1
        max_cnt = 0
        while True:
            max_cnt = max(max_cnt, one_cnt)

            if r == len(data) - 1:
                break

            one_cnt += 1 if data[r+1] == 1 else 0
            one_cnt -= 1 if data[l] == 1 else 0
            l += 1
            r += 1

        return window_len - max_cnt
```
