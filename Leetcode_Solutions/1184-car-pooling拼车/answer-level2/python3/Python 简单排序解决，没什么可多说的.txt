
![image.png](https://pic.leetcode-cn.com/71db6abd5a30fb10ceea9699347c052fce11f05a643b9b68f255ffc301fd1fa6-image.png)



```
'''
按时间戳升序排序，优先处理下车，如果中间出现容量不够情况
即返回失败
'''

from typing import List
class Solution:
    def carPooling(self, trips: List[List[int]], capacity: int) -> bool:
        buf = []
        for num, start, end in trips:
            buf.append((start, 1, num))
            buf.append((end, 0, num))

        buf.sort()

        cnt = 0
        for _, type, num in buf:
            cnt += num if type == 1 else -num
            if cnt > capacity:
                return False
        return True
```
