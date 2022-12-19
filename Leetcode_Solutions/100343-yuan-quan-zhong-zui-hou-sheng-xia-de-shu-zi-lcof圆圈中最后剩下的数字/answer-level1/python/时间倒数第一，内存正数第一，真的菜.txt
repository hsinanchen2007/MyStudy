### 解题思路
我太菜了
写了6个小时

### 代码

```python3
from operator import mod
class Solution:
    def lastRemaining(self, n: int, m: int) -> int:
        N = list(range(1,n+1))
        flag = 0
        if len(N) >= m:
            flag = 1
            pos = m-1
            last = N.pop(pos)
            while len(N)>= m:
                size = len(N)
                pos = (pos + m)%size -1
                if pos == -1:
                    pos = size-1
                last = N.pop(pos)
        if len(N)==0:
            return(last-1)
        if len(N)< m:
            if flag == 0:
                pos = mod(m,n) -1
                last = N.pop(pos)
                while len(N) != 0:
                    size = len(N)
                    right = (size - pos)
                    pos = (m -right )% size -1
                    if pos == -1:
                        pos = size-1
                    last = N.pop(pos)
            else:
                while len(N) != 0:
                    size = len(N)
                    right = (size - pos)
                    pos = (m -right )% size -1
                    if pos == -1:
                        pos = size-1
                    last = N.pop(pos)
                
        return(last -1)
```