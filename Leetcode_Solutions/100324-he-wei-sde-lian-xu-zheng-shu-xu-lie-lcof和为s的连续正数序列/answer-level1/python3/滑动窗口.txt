### 解题思路
此处撰写解题思路

### 代码

```python3
from collections import deque
class Solution:
    def findContinuousSequence(self, target: int) -> List[List[int]]:
      q, result = deque(), [] #q队列，模拟滑动窗口
      n, sum1 = 1, 1
      q.append(n)
      while len(q) > 1 or q[0] < target:
        if sum1 == target:
          if len(q) > 1:
            result.append(list(q))
            sum1 -= q.popleft()
            n += 1
            sum1 += n
            q.append(n)
        elif sum1 < target:
          n += 1
          sum1 += n
          q.append(n)
        else:
          sum1 -= q.popleft()   
      
      return result
```