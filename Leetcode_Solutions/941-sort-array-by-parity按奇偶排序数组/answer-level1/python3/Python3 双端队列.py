```
from collections import deque

class Solution:
    def sortArrayByParity(self, A: List[int]) -> List[int]:
        d = deque()
        for i in A:
            if i%2 == 0:
                d.appendleft(i)
            else:
                d.append(i)
        return d
```

使用了双端队列，偶数从左侧加入，奇数从右侧加入，最后返回队列